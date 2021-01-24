/**
 * @author Mr Dk.
 * @version 2021/01/24
 */

/*
    Given an unsorted array of integers nums, return the length of the longest
    continuous increasing subsequence (i.e. subarray). The subsequence must be
    strictly increasing.

    A continuous increasing subsequence is defined by two indices l and
    r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]]
    and for each l <= i < r, nums[i] < nums[i + 1].

    Example 1:
        Input: nums = [1,3,5,4,7]
        Output: 3
        Explanation:
            The longest continuous increasing subsequence is [1,3,5] with length 3.
            Even though [1,3,5,7] is an increasing subsequence, it is not continuous
            as elements 5 and 7 are separated by element 4.

    Example 2:
        Input: nums = [2,2,2,2,2]
        Output: 1
        Explanation:
            The longest continuous increasing subsequence is [2] with length 1.
            Note that it must be strictly increasing.

    Constraints:
        0 <= nums.length <= 104
        -109 <= nums[i] <= 109

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    如果栈为空，或者当前数比栈顶大，则入栈；否则将栈清空，并将当前元素入栈。
 */

#include <cassert>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> stack;
        int max_length = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (stack.empty() || nums[i] > stack[stack.size() - 1]) {
                stack.push_back(nums[i]);
                if ((int) stack.size() > max_length) {
                    max_length = stack.size();
                }
            } else {
                stack.clear();
                stack.push_back(nums[i]);
            }
        }

        return max_length;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 2,1,3 };
    assert(2 == s.findLengthOfLCIS(nums));

    nums = { 1,3,5,4,7 };
    assert(3 == s.findLengthOfLCIS(nums));

    nums = { 2,2,2,2,2 };
    assert(1 == s.findLengthOfLCIS(nums));

    return 0;
}
