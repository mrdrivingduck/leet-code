/**
 * @author Mr Dk.
 * @version 2021/03/04
 */

/*
    Given an integer array nums, return the length of the longest
    strictly increasing subsequence.

    A subsequence is a sequence that can be derived from an array
    by deleting some or no elements without changing the order of
    the remaining elements. For example, [3,6,2,7] is a subsequence
    of the array [0,3,1,6,2,2,7]. 

    Example 1:
        Input: nums = [10,9,2,5,3,7,101,18]
        Output: 4
        Explanation:
            The longest increasing subsequence is [2,3,7,101],
            therefore the length is 4.

    Example 2:
        Input: nums = [0,1,0,3,2,3]
        Output: 4

    Example 3:
        Input: nums = [7,7,7,7,7,7,7]
        Output: 1

    Constraints:
        1 <= nums.length <= 2500
        -104 <= nums[i] <= 104

    Follow up:
        Could you come up with the O(n2) solution?
        Could you improve it to O(n log(n)) time complexity?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    动态规划。在每一个位置，向前寻找可以进入的最长递增子序列，选择其中最长的，长度加 1。
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
    int lengthOfLIS(vector<int>& nums) {
        return length_of_lis_n2(nums);
    }

    int length_of_lis_n2(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int max = dp[0];

        for (size_t i = 1; i < nums.size(); i++) {
            // to find the shorter increasing sequence that can be added.
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    
    nums = { 10,9,2,5,3,7,101,18 };
    assert(4 == s.lengthOfLIS(nums));

    nums = { 0,1,0,3,2,3 };
    assert(4 == s.lengthOfLIS(nums));

    nums = { 7,7,7,7,7,7,7 };
    assert(1 == s.lengthOfLIS(nums));

    return 0;
}
