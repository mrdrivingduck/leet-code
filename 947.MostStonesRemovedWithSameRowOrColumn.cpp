/**
 * @author Mr Dk.
 * @version 2021/01/15
 */

/*
    On a 2D plane, we place n stones at some integer coordinate points.
    Each coordinate point may have at most one stone.

    A stone can be removed if it shares either the same row or the same
    column as another stone that has not been removed.

    Given an array stones of length n where stones[i] = [xi, yi] represents
    the location of the ith stone, return the largest possible number of
    stones that can be removed.

    Example 1:
        Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
        Output: 5
        Explanation: One way to remove 5 stones is as follows:
            1. Remove stone [2,2] because it shares the same row as [2,1].
            2. Remove stone [2,1] because it shares the same column as [0,1].
            3. Remove stone [1,2] because it shares the same row as [1,0].
            4. Remove stone [1,0] because it shares the same column as [0,0].
            5. Remove stone [0,1] because it shares the same row as [0,0].
            Stone [0,0] cannot be removed since it does not share a row/column
            with another stone still on the plane.

    Example 2:
        Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
        Output: 3
        Explanation: One way to make 3 moves is as follows:
            1. Remove stone [2,2] because it shares the same row as [2,0].
            2. Remove stone [2,0] because it shares the same column as [0,0].
            3. Remove stone [0,2] because it shares the same row as [0,0].
            Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

    Example 3:
        Input: stones = [[0,0]]
        Output: 0
        Explanation:
            [0,0] is the only stone on the plane, so you cannot remove it.

    Constraints:
        1 <= stones.length <= 1000
        0 <= xi, yi <= 104
        No two stones are at the same coordinate point.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    并查集，将同行同列的石头视为一个集合。最终，一个集合总能被删除到只有一个石头。
    所以，最终的结果就是石头总数减去集合数。
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
    int find(vector<int> &collection, int i) {
        if (collection[i] != i) {
            collection[i] = find(collection, collection[i]);
        }

        return collection[i];
    }

public:
    int removeStones(vector<vector<int>>& stones) {    
        vector<int> collection(stones.size());

        for (size_t i = 0; i < stones.size(); i++) {
            collection[i] = i;
        }

        for (size_t i = 0; i < stones.size(); i++) {
            for (size_t j = i + 1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    collection[find(collection, i)] = find(collection, j);
                }
            }
        }

        for (size_t i = 0; i < collection.size(); i++) {
            collection[i] = find(collection, collection[i]);
        }

        std::sort(collection.begin(), collection.end());
        int clusters = std::unique(collection.begin(), collection.end()) - collection.begin();

        return stones.size() - clusters;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> stones;

    stones = { {0,0},{0,1},{1,0},{1,2},{2,1},{2,2} };
    assert(5 == s.removeStones(stones));

    stones = { {0,0},{0,2},{1,1},{2,0},{2,2} };
    assert(3 == s.removeStones(stones));

    stones = { {0,0} };
    assert(0 == s.removeStones(stones));

    return 0;
}
