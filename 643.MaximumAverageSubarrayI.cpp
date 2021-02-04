/**
 * @author Mr Dk.
 * @version 2021/02/04
 */

/*
    Given an array consisting of n integers, find the contiguous subarray of
    given length k that has the maximum average value. And you need to output
    the maximum average value.

    Example 1:
        Input: [1,12,-5,-6,50,3], k = 4
        Output: 12.75
        Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
     

    Note:
        1 <= k <= n <= 30,000.
        Elements of the given array will be in the range [-10,000, 10,000].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximum-average-subarray-i
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    维护滑动窗口数字和的最大值即可。和最大意味着平均数最大。
 */

#include <cassert>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int max = INT32_MIN;
        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (i >= (size_t) k - 1) {
                if (sum > max) {
                    max = sum;
                }

                sum -= nums[i - k + 1];
            }
        }

        return ((double) max) / k;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 1,12,-5,-6,50,3 };
    assert(12.75 == s.findMaxAverage(nums, 4));

    nums = { 5 };
    assert(5 == s.findMaxAverage(nums, 1));

    return 0;
}
