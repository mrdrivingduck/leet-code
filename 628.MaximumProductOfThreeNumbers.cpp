/**
 * @author Mr Dk.
 * @version 2021/01/20
 */

/*
    Given an integer array nums, find three numbers whose product is maximum
    and return the maximum product. 

    Example 1:
        Input: nums = [1,2,3]
        Output: 6

    Example 2:
        Input: nums = [1,2,3,4]
        Output: 24

    Example 3:
        Input: nums = [-1,-2,-3]
        Output: -6

    Constraints:
        3 <= nums.length <= 10^4
        -1000 <= nums[i] <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximum-product-of-three-numbers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    如果数组中全是正数，那么最大值为最大三个数相乘；如果数组中全是负数，那么最大值也是
    最大三个数相乘 (绝对值最小)；如果又有负数又有正数，那么最大值应该是最小的两个负数
    乘以最大的正数。

    综上，最大值只有两种可能：最大三个数的乘积；或最小的两个数与最大一个数的乘积。
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
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return std::max(
            nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3],
            nums[0] * nums[1] * nums[nums.size() - 1]
        );
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 1,2,3 };
    assert(6 == s.maximumProduct(nums));

    nums = { 1,2,3,4 };
    assert(24 == s.maximumProduct(nums));

    nums = { -1,-2,-3 };
    assert(-6 == s.maximumProduct(nums));

    return 0;
}
