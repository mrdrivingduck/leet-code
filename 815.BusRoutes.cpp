/**
 * @author Mr Dk.
 * @version 2021/03/09
 */

/*
    You are given an array routes representing bus routes where routes[i]
    is a bus route that the ith bus repeats forever.

    For example, if routes[0] = [1, 5, 7], this means that the 0th bus
    travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
    You will start at the bus stop source (You are not on any bus initially),
    and you want to go to the bus stop target. You can travel between bus
    stops by buses only.

    Return the least number of buses you must take to travel from source
    to target. Return -1 if it is not possible. 

    Example 1:
        Input:
            routes = [[1,2,7],[3,6,7]], source = 1, target = 6
        Output: 2
        Explanation:
            The best strategy is take the first bus to the bus stop 7, then
            take the second bus to the bus stop 6.

    Example 2:
        Input:
            routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]],
            source = 15, target = 12
        Output: -1

    Constraints:
        1 <= routes.length <= 500.
        1 <= routes[i].length <= 105
        All the values of routes[i] are unique.
        sum(routes[i].length) <= 105
        0 <= routes[i][j] < 106
        0 <= source, target < 106

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/bus-routes
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    构造一张图，表示两条路线是否相交。查询得到起点和重点所在的路线，从起点
    所在的路线开始广度优先搜索，遍历所有与该路线交叉的路线，直到找到终点
    所在的路线。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::unordered_set;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        for (size_t i = 0; i < routes.size(); i++) {
            std::sort(routes[i].begin(), routes[i].end());
        }

        vector<vector<int>> is_intersect(routes.size());
        for (size_t i = 0; i < routes.size(); i++) {
            for (size_t j = i + 1; j < routes.size(); j++) {
                size_t a = 0;
                size_t b = 0;
                while (a < routes[i].size() && b < routes[j].size()) {
                    if (routes[i][a] < routes[j][b]) {
                        a++;
                    } else if (routes[i][a] > routes[j][b]) {
                        b++;
                    } else {
                        is_intersect[i].push_back(j);
                        is_intersect[j].push_back(i);
                        break;
                    }
                }
            }
        }

        queue<int> bfs;
        queue<int> step;
        unordered_set<int> target_routes;
        vector<bool> is_visited(routes.size(), false);
        for (size_t i = 0; i < routes.size(); i++) {
            if (std::binary_search(routes[i].begin(), routes[i].end(), source)) {
                bfs.push(i);
                step.push(1);
            }
            if (std::binary_search(routes[i].begin(), routes[i].end(), target)) {
                target_routes.insert(i);
            }
        }

        while (!bfs.empty()) {
            int route = bfs.front();
            int current_step = step.front();
            bfs.pop();
            step.pop();

            if (target_routes.find(route) != target_routes.end()) {
                return current_step;
            }

            is_visited[route] = true;
            for (size_t i = 0; i < is_intersect[route].size(); i++) {
                if (!is_visited[is_intersect[route][i]]) {
                    bfs.push(is_intersect[route][i]);
                    step.push(current_step + 1);
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> routes;

    routes = {
        { 1,7 },
        { 3,5 }
    };
    assert(0 == s.numBusesToDestination(routes, 5, 5));

    routes = {
        { 1,2,7 },
        { 3,6,7 }
    };
    assert(2 == s.numBusesToDestination(routes, 1, 6));

    routes = {
        { 7,12 },
        { 4,5,15 },
        { 6 },
        { 15,19 },
        { 9,12,13 }
    };
    assert(-1 == s.numBusesToDestination(routes, 15, 12));

    return 0;
}
