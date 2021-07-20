/**
 * @author Mr Dk.
 * @version 2021/07/20
 */

/*
    The pair sum of a pair (a,b) is equal to a + b. The maximum pair
    sum is the largest pair sum in a list of pairs.

    For example, if we have pairs (1,5), (2,3), and (4,4), the maximum
    pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
    Given an array nums of even length n, pair up the elements of nums
    into n / 2 pairs such that:

        Each element of nums is in exactly one pair, and
        The maximum pair sum is minimized.

    Return the minimized maximum pair sum after optimally pairing up the elements.

    Example 1:
        Input: nums = [3,5,2,3]
        Output: 7
        Explanation:
            The elements can be paired up into pairs (3,3) and (5,2).
            The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.

    Example 2:
        Input: nums = [3,5,4,2,4,6]
        Output: 8
        Explanation:
            The elements can be paired up into pairs (3,5), (4,4), and (6,2).
            The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.

    Constraints:
        n == nums.length
        2 <= n <= 105
        n is even.
        1 <= nums[i] <= 105

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/minimize-maximum-pair-sum-in-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    为使序列中两数之和的最大值尽可能小，那么应当尽可能使一个更小的数与一个更大的数相加。
    因此先将序列排序，然后依次将数从首位依次相加，相加的最大值应当就是最小化的数对和最大值。
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
    int minPairSum(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        std::sort(nums.begin(), nums.end());

        int max = nums[left] + nums[right];
        while (++left < --right) {
            max = std::max(max, nums[left] + nums[right]);
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 3,5,2,3 };
    assert(7 == s.minPairSum(nums));

    nums = { 3,5,4,2,4,6 };
    assert(8 == s.minPairSum(nums));

    return 0;
}
