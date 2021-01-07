/**
 * @author Mr Dk.
 * @version 2021/01/07
 */

/*
    There are n cities. Some of them are connected, while some are not.
    If city a is connected directly with city b, and city b is connected
    directly with city c, then city a is connected indirectly with city c.

    A province is a group of directly or indirectly connected cities and
    no other cities outside of the group.

    You are given an n x n matrix isConnected where isConnected[i][j] = 1
    if the ith city and the jth city are directly connected, and
    isConnected[i][j] = 0 otherwise.

    Return the total number of provinces. 

    Example 1:
        Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
        Output: 2

    Example 2:
        Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
        Output: 3

    Constraints:
        1 <= n <= 200
        n == isConnected.length
        n == isConnected[i].length
        isConnected[i][j] is 1 or 0.
        isConnected[i][i] == 1
        isConnected[i][j] == isConnected[j][i]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/number-of-provinces
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    深度优先遍历。从一个城市进入 DFS 递归遍历后，应该能遍历到这个省内的所有
    城市。所以只需要计算从几个城市开始 DFS 就能得知有几个省份。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count = 0;

        for (size_t i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& map, vector<bool> &visited, size_t current) {
        for (size_t i = 0; i < map[current].size(); i++) {
            if (!visited[i] && map[current][i]) {
                visited[i] = true;
                dfs(map, visited, i);
            }
        }
    }
};

int main() {
    Solution s;    
    vector<vector<int>> map;

    map = { { 1,1,0 }, { 1,1,0 }, { 0,0,1 } };
    assert(2 == s.findCircleNum(map));

    map = { { 1,0,0 }, { 0,1,0 }, { 0,0,1 } };
    assert(3 == s.findCircleNum(map));

    return 0;
}
