/**
 * @author Mr Dk.
 * @version 2021/09/17
 */

/*
    There are a total of numCourses courses you have to take, labeled
    from 0 to numCourses - 1. You are given an array prerequisites where
    prerequisites[i] = [ai, bi] indicates that you must take course bi
    first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you
    have to first take course 1.
    Return the ordering of courses you should take to finish all courses.
    If there are many valid answers, return any of them. If it is
    impossible to finish all courses, return an empty array. 

    Example 1:
        Input: numCourses = 2, prerequisites = [[1,0]]
        Output: [0,1]
        Explanation:
            There are a total of 2 courses to take. To take course 1 you
            should have finished course 0. So the correct course order
            is [0,1].

    Example 2:
        Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
        Output: [0,2,1,3]
        Explanation:
            There are a total of 4 courses to take. To take course 3 you
            should have finished both courses 1 and 2. Both courses 1 and
            2 should be taken after you finished course 0.
            So one correct course order is [0,1,2,3]. Another correct
            ordering is [0,2,1,3].

    Example 3:
        Input: numCourses = 1, prerequisites = []
        Output: [0]

    Constraints:
        1 <= numCourses <= 2000
        0 <= prerequisites.length <= numCourses * (numCourses - 1)
        prerequisites[i].length == 2
        0 <= ai, bi < numCourses
        ai != bi
        All the pairs [ai, bi] are distinct.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/course-schedule-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    一道经典的拓扑排序题。解决思路基本为，维护好每个节点的入度 (也就是先导
    课程)。挑选出入度为 0 的节点 (没有任何先导课程的课程) 加入队列 (进行学习)，
    学习完毕后，递减与这门课相关的课程节点的入度 - 如果入度减至 0，则也可以
    加入队列进行学习。直到队列为空为止。

    由于上述过程中需要维护每一个节点的邻接节点，因此从性能角度出发可以使用
    二维矩阵的邻接表或者 hash table。从数据的规模上看，hash table 更适合。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::queue;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> next_to;
        unordered_map<int, vector<int>>::iterator iter;
        vector<int> in_degree(numCourses, 0);

        for (size_t i = 0; i < prerequisites.size(); i++) {
            iter = next_to.find(prerequisites[i][1]);
            if (iter == next_to.end()) {
                vector<int> next(1, prerequisites[i][0]);
                next_to.insert(std::make_pair(prerequisites[i][1], next));
            } else {
                iter->second.push_back(prerequisites[i][0]);
            }

            in_degree[prerequisites[i][0]]++;
        }

        queue<int> order;
        for (size_t i = 0; i < in_degree.size(); i++) {
            if (!in_degree[i]) {
                order.push(i);
            }
        }

        vector<int> result;
        while (!order.empty()) {
            int current = order.front();
            result.push_back(current);
            order.pop();

            iter = next_to.find(current);
            if (iter != next_to.end()) {
                for (size_t i = 0; i < iter->second.size(); i++) {
                    in_degree[iter->second[i]]--;
                    if (!in_degree[iter->second[i]]) {
                        order.push(iter->second[i]);
                    }
                }
            }
        }

        if ((int) result.size() != numCourses) {
            result.clear();
        }

        // for (size_t i = 0; i < result.size(); i++) {
        //     cout << result[i] << " ";
        // }
        // cout << endl;

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> order;
    vector<vector<int>> preq;

    preq = { { 1,0 } };
    order = { 0,1 };
    assert(order == s.findOrder(2, preq));

    preq = { { 1,0 }, { 2,0 }, { 3,1 }, { 3,2 } };
    order = { 0,1,2,3 };
    assert(order == s.findOrder(4, preq));

    preq = {  };
    order = { 0 };
    assert(order == s.findOrder(1, preq));

    return 0;
}
