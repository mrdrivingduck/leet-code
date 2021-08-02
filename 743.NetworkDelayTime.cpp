/**
 * @author Mr Dk.
 * @version 2021/08/02
 */

/*
    You are given a network of n nodes, labeled from 1 to n. You are also
    given times, a list of travel times as directed edges times[i] = (ui,
    vi, wi), where ui is the source node, vi is the target node, and wi is
    the time it takes for a signal to travel from source to target.

    We will send a signal from a given node k. Return the time it takes for
    all the n nodes to receive the signal. If it is impossible for all the n
    nodes to receive the signal, return -1. 

    Example 1:
        Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
        Output: 2

    Example 2:
        Input: times = [[1,2,1]], n = 2, k = 1
        Output: 1

    Example 3:
        Input: times = [[1,2,1]], n = 2, k = 2
        Output: -1

    Constraints:
        1 <= k <= n <= 100
        1 <= times.length <= 6000
        times[i].length == 3
        1 <= ui, vi <= n
        ui != vi
        0 <= wi <= 100
        All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/network-delay-time
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    Dijkstra 算法算出起点到所有顶点的最短路径，然后选出最大的值，就是信号传遍
    所有顶点的用时。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        vector<int> distance(n, INT32_MAX);
        vector<bool> visited(n, false);

        for (size_t i = 0; i < times.size(); i++) {
            matrix[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }

        distance[k - 1] = 0;

        for (int i = 0; i < n; i++) {
            int min_index = -1;

            for (size_t j = 0; j < visited.size(); j++) {
                if (!visited[j] &&
                    (min_index == -1 || distance[j] < distance[min_index])) {
                    min_index = j;
                }
            }

            visited[min_index] = true;

            for (size_t j = 0; j < visited.size(); j++) {
                if (matrix[min_index][j] != -1 &&
                    distance[j] - matrix[min_index][j] > distance[min_index]) {
                    distance[j] = distance[min_index] + matrix[min_index][j];
                }
            }
        }

        std::sort(distance.begin(), distance.end(), std::greater<int>());

        if (distance[0] == INT32_MAX) {
            return -1;
        }
        
        return distance[0];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> times;
    
    times = { { 2,1,1 }, { 2,3,1 }, { 3,4,1 } };
    assert(2 == s.networkDelayTime(times, 4, 2));

    times = { { 1,2,1 } };
    assert(1 == s.networkDelayTime(times, 2, 1));

    times = { { 1,2,1 } };
    assert(-1 == s.networkDelayTime(times, 2, 2));

    return 0;
}
