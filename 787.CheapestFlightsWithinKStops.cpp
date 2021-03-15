/**
 * @author Mr Dk.
 * @version 2021/03/15
 */

/*
    There are n cities connected by m flights. Each flight starts from
    city u and arrives at v with a price w.

    Now given all the cities and flights, together with starting city
    src and the destination dst, your task is to find the cheapest price
    from src to dst with up to k stops. If there is no such route,
    output -1.

    Example 1:
        Input: 
            n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
            src = 0, dst = 2, k = 1
        Output:
            200
        Explanation: 
            The graph looks like this:
            The cheapest price from city 0 to city 2 with at most 1 stop
            costs 200, as marked red in the picture.

    Example 2:
        Input: 
            n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
            src = 0, dst = 2, k = 0
        Output:
            500
        Explanation: 
            The graph looks like this:
            The cheapest price from city 0 to city 2 with at most 0 stop
            costs 500, as marked blue in the picture.

    Constraints:
        The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
        The size of flights will be in range [0, n * (n - 1) / 2].
        The format of each flight will be (src, dst, price).
        The price of each flight will be in the range [1, 10000].
        k is in the range of [0, n - 1].
        There will not be any duplicated flights or self cycles.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    借用 Dijkstra 算法的思想，借用优先队列维护所有从确定最短距离的点出发的边。
    同时，对于每一条这样的边，还需要维护已经累积的路径长度和步数。如果步数超了，
    那么将不能成为最短路径。

    优先队列中维护的信息：边起点，累计距离，步数。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <queue>
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::queue;

struct comp {
    bool operator()(vector<int> &flight1, vector<int> &flight2) {
        return flight1[1] > flight2[1];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // <src, value, k>
        priority_queue<vector<int>, vector<vector<int>>, comp> heap;
        for (size_t i = 0; i < flights.size(); i++) {
            if (flights[i][0] == src) {
                heap.push({ flights[i][1], flights[i][2], K });
            }
        }
        
        while (!heap.empty()) {
            vector<int> entry = heap.top();
            heap.pop();

            int source = entry[0];
            int accumulated_path = entry[1];
            int k = entry[2];

            if (source == dst) {
                return accumulated_path;
            }

            if (k) {
                for (size_t i = 0; i < flights.size(); i++) {
                    if (flights[i][0] == source) {
                        heap.push({ flights[i][1], accumulated_path + flights[i][2], k - 1 });
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> flights;

    flights = {
        { 0,1,1 },
        { 0,2,5 },
        { 1,2,1 },
        { 2,3,1 }
    };
    assert(6 == s.findCheapestPrice(4, flights, 0, 3, 1));

    flights = {
        { 0,1,100 },
        { 1,2,100 },
        { 0,2,500 }
    };
    assert(200 == s.findCheapestPrice(3, flights, 0, 2, 1));
    assert(500 == s.findCheapestPrice(3, flights, 0, 2, 0));


    return 0;
}
