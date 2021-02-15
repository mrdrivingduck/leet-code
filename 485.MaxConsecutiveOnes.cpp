/**
 * @author Mr Dk.
 * @version 2021/02/15
 */

/*
    Given a binary array, find the maximum number of consecutive 1s in
    this array.

    Example 1:
        Input: [1,1,0,1,1,1]
        Output: 3
        Explanation:
            The first two digits or the last three digits are consecutive 1s.
            The maximum number of consecutive 1s is 3.

    Note:
        The input array will only contain 0 and 1.
        The length of input array is a positive integer and will not exceed
        10,000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/max-consecutive-ones
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    通过一个滑动窗口维护连续为 1 的区间。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        size_t left = 0;
        size_t right = 0;
        while (right < nums.size()) {
            if (!nums[right]) {
                left = right + 1;
            } else {
                max = std::max(max, (int) (right - left + 1));
            }
            right++;
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 1,0,1,1,0,1 };
    assert(2 == s.findMaxConsecutiveOnes(nums));

    nums = { 1,1,0,1,1,1 };
    assert(3 == s.findMaxConsecutiveOnes(nums));

    return 0;
}
