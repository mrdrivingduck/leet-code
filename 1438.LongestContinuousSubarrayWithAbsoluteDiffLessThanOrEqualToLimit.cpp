/**
 * @author Mr Dk.
 * @version 2021/02/21
 */

/*
    Given an array of integers nums and an integer limit, return the size
    of the longest non-empty subarray such that the absolute difference
    between any two elements of this subarray is less than or equal to
    limit. 

    Example 1:
        Input: nums = [8,2,4,7], limit = 4
        Output: 2 
        Explanation: All subarrays are: 
            [8] with maximum absolute diff |8-8| = 0 <= 4.
            [8,2] with maximum absolute diff |8-2| = 6 > 4. 
            [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
            [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
            [2] with maximum absolute diff |2-2| = 0 <= 4.
            [2,4] with maximum absolute diff |2-4| = 2 <= 4.
            [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
            [4] with maximum absolute diff |4-4| = 0 <= 4.
            [4,7] with maximum absolute diff |4-7| = 3 <= 4.
            [7] with maximum absolute diff |7-7| = 0 <= 4. 
        Therefore, the size of the longest subarray is 2.

    Example 2:
        Input: nums = [10,1,2,4,7,2], limit = 5
        Output: 4 
        Explanation:
            The subarray [2,4,7,2] is the longest since the maximum
            absolute diff is |2-7| = 5 <= 5.

    Example 3:
        Input: nums = [4,2,2,2,4,4,2,2], limit = 0
        Output: 3

    Constraints:
        1 <= nums.length <= 10^5
        1 <= nums[i] <= 10^9
        0 <= limit <= 10^9

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    使用一个 multiset 维护滑动窗口内的有序序列，方便快速得到最大值和最小值。
    根据最大值和最小值之差来决定减小或是增大窗口。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::multiset;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;

        int left = 0;
        int right = 0;
        int longest = 0;

        while (right < (int) nums.size()) {
            window.insert(nums[right]);

            while (*window.rbegin() - *window.begin() > limit) {
                multiset<int>::iterator iter = window.find(nums[left]);
                window.erase(iter);
                left++;
            }

            longest = std::max(longest, right - left + 1);

            right++;
        }

        return longest;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 8,2,4,7 };
    assert(2 == s.longestSubarray(nums, 4));

    nums = { 10,1,2,4,7,2 };
    assert(4 == s.longestSubarray(nums, 5));

    nums = { 4,2,2,2,4,4,2,2 };
    assert(3 == s.longestSubarray(nums, 0));

    return 0;
}
