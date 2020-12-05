/**
 * @author Mr Dk.
 * @version 2020/12/05
 */

/*
    Given a characters array tasks, representing the tasks a CPU needs to do,
    where each letter represents a different task. Tasks could be done in any
    order. Each task is done in one unit of time. For each unit of time, the
    CPU could complete either one task or just be idle.

    However, there is a non-negative integer n that represents the cooldown
    period between two same tasks (the same letter in the array), that is that
    there must be at least n units of time between any two same tasks.

    Return the least number of units of times that the CPU will take to finish all the given tasks.

    Example 1:
        Input: tasks = ["A","A","A","B","B","B"], n = 2
        Output: 8
        Explanation: 
            A -> B -> idle -> A -> B -> idle -> A -> B
            There is at least 2 units of time between any two same tasks.

    Example 2:
        Input: tasks = ["A","A","A","B","B","B"], n = 0
        Output: 6
        Explanation: On this case any permutation of size 6 would work since n = 0.
            ["A","A","A","B","B","B"]
            ["A","B","A","B","A","B"]
            ["B","B","B","A","A","A"]
            ...
            And so on.

    Example 3:
        Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
        Output: 16
        Explanation: 
            One possible solution is
            A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

    Constraints:
        1 <= task.length <= 104
        tasks[i] is upper-case English letter.
        The integer n is in the range [0, 100].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/task-scheduler
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    为了让 CPU 尽量不空转，应当尽可能让任务数量较多的任务类型运行，同时尽可能填满中间的冷却时间。
    使用了一个优先队列，每次取出的任务都是最优的：冷却时间最短 / 任务数量最多。然后模拟任务调度
    的过程。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

typedef struct task {
    int count;
    int cold_time;
} task;

bool compare(struct task &task1, struct task &task2) {
    return task1.cold_time == task2.cold_time ?
            task1.count < task2.count :
            task1.cold_time > task2.cold_time;
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<task> all_tasks(26);
        for (size_t i = 0; i < all_tasks.size(); i++) {
            all_tasks[i] = { 0, 0 };
        }

        for (size_t i = 0; i < tasks.size(); i++) {
            all_tasks[tasks[i] - 'A'].count++;
        }

        // merge only effective tasks
        size_t empty = 0;
        for (size_t i = 0; i < all_tasks.size(); i++) {
            if (i == empty && all_tasks[i].count > 0) {
                empty++;
            } else if (all_tasks[i].count > 0) {
                all_tasks[empty] = all_tasks[i];
                empty++;
            }
        }
        all_tasks.resize(empty);

        std::make_heap(all_tasks.begin(), all_tasks.end(), compare);
        int time = 0;

        while (!all_tasks.empty()) {
            // fast forward
            if (all_tasks[0].cold_time != 0) {
                int remaining = all_tasks[0].cold_time;
                time += remaining;
                for (size_t i = 0; i < all_tasks.size(); i++) {
                    all_tasks[i].cold_time -= remaining;
                }
            } else {
                // get the hignest priority task
                std::pop_heap(all_tasks.begin(), all_tasks.end(), compare);
                // execute
                all_tasks[all_tasks.size() - 1].count--;
                // accumulate time
                time++;
                all_tasks[all_tasks.size() - 1].cold_time = n;
                for (size_t i = 0; i < all_tasks.size() - 1; i++) {
                    if (all_tasks[i].cold_time > 0) {
                        all_tasks[i].cold_time--;
                    }
                }
                // remove the task if complete
                if (all_tasks[all_tasks.size() - 1].count == 0) {
                    all_tasks.pop_back();
                }
                // re-order the priority again
                std::make_heap(all_tasks.begin(), all_tasks.end(), compare);
            }
        }

        return time;
    }
};

int main()
{
    Solution s;
    vector<char> tasks;
    
    tasks = { 'A','A','A','B','B','B' };
    cout << s.leastInterval(tasks, 2) << endl;
    cout << s.leastInterval(tasks, 0) << endl;

    tasks = { 'A','A','A','A','A','A','B','C','D','E','F','G' };
    cout << s.leastInterval(tasks, 2) << endl;

    tasks = { 'A' };
    cout << s.leastInterval(tasks, 1) << endl;

    return 0;
}
