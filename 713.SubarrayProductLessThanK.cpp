/**
 * @author Mr Dk.
 * @version 2021/08/10
 */

/*
    Given an array of integers nums and an integer k, return the number of
    contiguous subarrays where the product of all the elements in the
    subarray is strictly less than k.

    Example 1:
        Input: nums = [10,5,2,6], k = 100
        Output: 8
        Explanation:
            The 8 subarrays that have product less than 100 are:
            [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
            Note that [10, 5, 2] is not included as the product of 100 is not 
            strictly less than k.

    Example 2:
        Input: nums = [1,2,3], k = 0
        Output: 0

    Constraints:
        1 <= nums.length <= 3 * 104
        1 <= nums[i] <= 1000
        0 <= k <= 106

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/subarray-product-less-than-k
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    滑动窗口。保持窗口内的乘积小于目标值，然后累加子数组的个数。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        size_t left = 0;
        size_t right = 0;
        int product = 1;
        int arrays = 0;

        while (right < nums.size()) {
            product *= nums[right];
            right++;

            while (product >= k && left < right) {
                product /= nums[left];
                left++;
            }

            if (left == right) {
                continue;
            }

            arrays += (right - left);
        }

        return arrays;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    
    nums = { 10,5,2,6 };
    assert(8 == s.numSubarrayProductLessThanK(nums, 100));

    nums = { 1,2,3 };
    assert(0 == s.numSubarrayProductLessThanK(nums, 0));

    return 0;
}
