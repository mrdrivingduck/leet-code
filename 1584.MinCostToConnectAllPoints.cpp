/**
 * @author Mr Dk.
 * @version 2021/01/19
 */

/*
    You are given an array points representing integer coordinates of some
    points on a 2D-plane, where points[i] = [xi, yi].

    The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
    distance between them: |xi - xj| + |yi - yj|, where |val| denotes the
    absolute value of val.

    Return the minimum cost to make all points connected. All points are
    connected if there is exactly one simple path between any two points.

    Example 1:
        Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
        Output: 20
        Explanation:
            We can connect the points as shown above to get the minimum
            cost of 20. Notice that there is a unique path between every
            pair of points.

    Example 2:
        Input: points = [[3,12],[-2,5],[-4,1]]
        Output: 18

    Example 3:
        Input: points = [[0,0],[1,1],[1,0],[-1,1]]
        Output: 4

    Example 4:
        Input: points = [[-1000000,-1000000],[1000000,1000000]]
        Output: 4000000

    Example 5:
        Input: points = [[0,0]]
        Output: 0

    Constraints:
        1 <= points.length <= 1000
        -106 <= xi, yi <= 106
        All pairs (xi, yi) are distinct.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/min-cost-to-connect-all-points
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    最小生成树 Kruskal 算法。将所有的边进行排序，从最短的边开始算起，如果边的
    两个端点不属于同一个连通分量，则将该边留下，并将两个端点合并到一个连通分量
    中。这样就可以得出最小生成树。

    是否同属于一个连通分量可以通过并查集来实现。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using std::cout;
using std::endl;
using std::vector;

struct Edge {
    int x_index;
    int y_index;
    int len;

    Edge(int x_index, int y_index, int len) : x_index(x_index), y_index(y_index), len(len) {}
};

bool cmp(struct Edge &e1, struct Edge &e2) {
    return e1.len < e2.len;
}

class Solution {
private:
    int find(vector<int> &collection, int index) {
        if (index != collection[index]) {
            collection[index] = find(collection, collection[index]);
        }

        return collection[index];
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // find all edges.
        vector<Edge> edges;
        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                int len = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                struct Edge edge(i, j, len);
                edges.push_back(edge);
            }
        }

        // sort edges according to edge length.
        std::sort(edges.begin(), edges.end(), cmp);

        // initialize disjoint set.
        vector<int> collection(points.size());
        for (size_t i = 0; i < collection.size(); i++) {
            collection[i] = i;
        }

        int total_len = 0;
        int edges_count = 0;
        // start from the shortest edge.
        for (size_t i = 0; i < edges.size(); i++) {
            int x_index = edges[i].x_index;
            int y_index = edges[i].y_index;

            // two points don't belong to the same group.
            if (collection[find(collection, y_index)] != find(collection, x_index)) {
                collection[find(collection, y_index)] = find(collection, x_index);
                total_len += edges[i].len;

                // only (n - 1) edges is needed.
                edges_count++;
                if (edges_count == (int) points.size() - 1) {
                    break;
                }
            }
        }

        return total_len;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points;

    points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    assert(20 == s.minCostConnectPoints(points));

    points = {{3,12},{-2,5},{-4,1}};
    assert(18 == s.minCostConnectPoints(points));

    points = {{0,0},{1,1},{1,0},{-1,1}};
    assert(4 == s.minCostConnectPoints(points));

    points = {{-1000000,-1000000},{1000000,1000000}};
    assert(4000000 == s.minCostConnectPoints(points));

    points = {{0,0}};
    assert(0 == s.minCostConnectPoints(points));

    return 0;
}
