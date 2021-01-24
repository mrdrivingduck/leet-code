/**
 * @author Mr Dk.
 * @version 2021/01/24
 */

/*
    There are n computers numbered from 0 to n-1 connected by ethernet cables
    connections forming a network where connections[i] = [a, b] represents a
    connection between computers a and b. Any computer can reach any other
    computer directly or indirectly through the network.

    Given an initial computer network connections. You can extract certain
    cables between two directly connected computers, and place them between
    any pair of disconnected computers to make them directly connected.
    Return the minimum number of times you need to do this in order to make
    all the computers connected. If it's not possible, return -1. 

    Example 1:
        Input: n = 4, connections = [[0,1],[0,2],[1,2]]
        Output: 1
        Explanation:
            Remove cable between computer 1 and 2 and place between computers 1 and 3.

    Example 2:
        Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
        Output: 2

    Example 3:
        Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
        Output: -1
        Explanation: There are not enough cables.

    Example 4:
        Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
        Output: 0

    Constraints:
        1 <= n <= 10^5
        1 <= connections.length <= min(n*(n-1)/2, 10^5)
        connections[i].length == 2
        0 <= connections[i][0], connections[i][1] < n
        connections[i][0] != connections[i][1]
        There are no repeated connections.
        No two computers are connected by more than one cable.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    并查集。在构造并查集的同时，统计额外边的个数。为使 n 的结点保持相连，至少需要 n - 1 条边，
    此外多出来的边就是额外边，可以用于连接不相连的集合。

    计算最终的集合数，集合数 - 1 就是能把这些集合连到一起的最少边数。如果额外边的个数多于这个
    最少边数，那么就可以通过移动额外边来使不同的集合连在一起。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
private:
    int find_root(vector<int> &computers, int i) {
        if (computers[i] != i) {
            computers[i] = find_root(computers, computers[i]);
        }
        return computers[i];
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> computers(n);
        for (size_t i = 0; i < computers.size(); i++) {
            computers[i] = i;
        }

        int extra_edge = 0;
        for (size_t i = 0; i < connections.size(); i++) {
            int root1 = find_root(computers, connections[i][0]);
            int root2 = find_root(computers, connections[i][1]);
            if (root1 != root2) {
                computers[root2] = root1;
            } else {
                extra_edge++;
            }
        }

        // path compression
        for (size_t i = 0; i < computers.size(); i++) {
            computers[i] = find_root(computers, i);
        }

        std::sort(computers.begin(), computers.end());
        int groups = std::unique(computers.begin(), computers.end()) - computers.begin();

        if (extra_edge >= groups - 1) {
            return groups - 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> cables;

    cables = { { 0,1 }, { 0,2 }, { 1,2 } };
    assert(1 == s.makeConnected(4, cables));

    cables = { { 0,1 }, { 0,2 }, { 0,3 }, { 1,2 }, { 1,3 } };
    assert(2 == s.makeConnected(6, cables));

    cables = { { 0,1 }, { 0,2 }, { 0,3 }, { 1,2 } };
    assert(-1 == s.makeConnected(6, cables));

    cables = { { 0,1 }, { 0,2 }, { 3,4 }, { 2,3 } };
    assert(0 == s.makeConnected(5, cables));

    return 0;
}
