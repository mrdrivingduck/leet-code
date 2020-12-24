/**
 * @author Mr Dk.
 * @version 2020/12/24 🎄🎅
 */

/*
    There are N children standing in a line. Each child is assigned a
    rating value.

    You are giving candies to these children subjected to the following
    requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.
    What is the minimum candies you must give?

    Example 1:
        Input: [1,0,2]
        Output: 5
        Explanation: You can allocate to the first, second and third child
                with 2, 1, 2 candies respectively.

    Example 2:
        Input: [1,2,2]
        Output: 4
        Explanation: You can allocate to the first, second and third child
                with 1, 2, 1 candies respectively. The third child gets 1
                candy because it satisfies the above two conditions.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/candy
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    从左边开始遍历，如果遇到评分更高的，就将糖果数量提升至比前一个人多 1；
    从右边开始遍历，依此类推。得到分别满足左右两个规则的最小糖果数量数组。

    遍历这两个数组，给每个孩子分发同时满足左右规则的最少糖果数，即两个
    数组同一位置上糖果数量的较大的那个值。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size(), 1);
        vector<int> right(ratings.size(), 1);

        for (size_t i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        
        int count = 0;
        for (size_t i = 0; i < ratings.size(); i++) {
            count += (left[i] < right[i] ? right[i] : left[i]);
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<int> children;

    children = { 1,2,87,87,87,2,1 };
    assert(13 == s.candy(children));
    
    children = { 1,0,2 };
    assert(5 == s.candy(children));

    children = { 1,2,2 };
    assert(4 == s.candy(children));

    return 0;
}