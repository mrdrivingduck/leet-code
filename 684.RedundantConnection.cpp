/**
 * @author Mr Dk.
 * @version 2021/01/13
 */

/*
    In this problem, a tree is an undirected graph that is connected
    and has no cycles.

    The given input is a graph that started as a tree with N nodes
    (with distinct values 1, 2, ..., N), with one additional edge added.
    The added edge has two different vertices chosen from 1 to N, and was
    not an edge that already existed.

    The resulting graph is given as a 2D-array of edges. Each element of
    edges is a pair [u, v] with u < v, that represents an undirected edge
    connecting nodes u and v.

    Return an edge that can be removed so that the resulting graph is a tree
    of N nodes. If there are multiple answers, return the answer that occurs
    last in the given 2D-array. The answer edge [u, v] should be in the same
    format, with u < v.

    Example 1:
        Input: [[1,2], [1,3], [2,3]]
        Output: [2,3]
        Explanation: The given undirected graph will be like this:
               1
             / \
            2 - 3

    Example 2:
        Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
        Output: [1,4]
        Explanation: The given undirected graph will be like this:
            5 - 1 - 2
                |   |
                4 - 3

    Note:
    The size of the input 2D-array will be between 3 and 1000.
    Every integer represented in the 2D-array will be between 1 and N,
    where N is the size of the input array.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/redundant-connection
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    一个 N 个结点的无环图只会有 N - 1 条边。在本题中，会给出 N 条边。
    所以只需要通过并查集来过滤即可：如果边的两个端点已经在同一个集合中，
    那么再次引入这条边将会导致环的出现，因此直接将这条边返回即可。

    注意这道题坑爹的地方是，结点不是 0-indexed 而是 1-indexed，所以
    在实现过程中要把边的两个顶点数值减 1。
 */

#include <cassert>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
private:
    vector<int> collections;

    int find(int i) {
        if (collections[i] != i) {
            collections[i] = find(collections[i]);
        }
        return collections[i];
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        collections.resize(edges.size());
        for (size_t i = 0; i < collections.size(); i++) {
            collections[i] = i;
        }

        for (size_t i = 0; i < edges.size(); i++) {
            int root1 = find(edges[i][0] - 1);
            int root2 = find(edges[i][1] - 1);

            if (root1 == root2) {
                return edges[i];
            }

            collections[root1] = root2;
        }

        return edges[edges.size() - 1]; // back up, no use.
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges;
    vector<int> edge;
    
    edges = { { 1,2 }, { 1,3 }, { 2,3 } };
    edge = { 2,3 };
    assert(edge == s.findRedundantConnection(edges));

    edges = { { 1,2 }, { 2,3 }, { 3,4 }, { 1,4 }, { 1,5 } };
    edge = { 1,4 };
    assert(edge == s.findRedundantConnection(edges));

    return 0;
}
