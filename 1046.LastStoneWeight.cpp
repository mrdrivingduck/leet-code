/**
 * @author Mr Dk.
 * @version 2020/12/30
 */

/*
    We have a collection of stones, each stone has a positive integer weight.

    Each turn, we choose the two heaviest stones and smash them together.
    Suppose the stones have weights x and y with x <= y. The result of this
    smash is:
        If x == y, both stones are totally destroyed;
        If x != y, the stone of weight x is totally destroyed, and the stone
        of weight y has new weight y-x.
    At the end, there is at most 1 stone left. Return the weight of this stone
    (or 0 if there are no stones left.) 

    Example 1:
        Input: [2,7,4,1,8,1]
        Output: 1
        Explanation: 
            We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
            we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
            we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
            we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.

    Note:
        1 <= stones.length <= 30
        1 <= stones[i] <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/last-stone-weight
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    使用优先队列或堆可以轻松实现。注意最终堆为空的特殊情况即可。
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
    int lastStoneWeight(vector<int>& stones) {
        std::make_heap(stones.begin(), stones.end());

        while (stones.size() > 1) {
            int x = stones[0];
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            int y = stones[0];
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            if ((x = x - y)) {
                if (x < 0) {
                    x = -x;
                }
                stones.push_back(x);
                std::push_heap(stones.begin(), stones.end());
            }
        }

        if (stones.empty()) {
            return 0;
        }

        return stones[0];
    }
};

int main()
{
    Solution s;
    vector<int> stones;

    stones = { 2,7,4,1,8,1 };
    assert(1 == s.lastStoneWeight(stones));

    stones = { 2,2 };
    assert(0 == s.lastStoneWeight(stones));

    return 0;
}
