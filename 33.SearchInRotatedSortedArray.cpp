/**
 * @author Mr Dk.
 * @version 2021/04/07
 */

/*
    There is an integer array nums sorted in ascending order (with
    distinct values).

    Prior to being passed to your function, nums is rotated at an
    unknown pivot index k (0 <= k < nums.length) such that the
    resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0],
    nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7]
    might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the rotation and an integer target,
    return the index of target if it is in nums, or -1 if it is not in nums.

    Example 1:
        Input: nums = [4,5,6,7,0,1,2], target = 0
        Output: 4

    Example 2:
        Input: nums = [4,5,6,7,0,1,2], target = 3
        Output: -1

    Example 3:
        Input: nums = [1], target = 0
        Output: -1

    Constraints:
        1 <= nums.length <= 5000
        -104 <= nums[i] <= 104
        All values of nums are unique.
        nums is guaranteed to be rotated at some pivot.
        -104 <= target <= 104

    Follow up: Can you achieve this in O(log n) time complexity?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    找到旋转点，以该点为边界进行二分查找。
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
    int search(vector<int>& nums, int target) {
        size_t i = 0;
        size_t pos;
        for (; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                break;
            }
        }

        if (nums[i] == target) {
            return i;
        }

        pos = std::lower_bound(nums.begin(), nums.begin() + i, target) - nums.begin();
        if (pos < nums.size() && nums[pos] == target) {
            return pos;
        }
        pos = std::lower_bound(nums.begin() + i + 1, nums.end(), target) - nums.begin();
        if (pos < nums.size() && nums[pos] == target) {
            return pos;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 4,5,6,7,0,1,2 };
    assert(4 == s.search(nums, 0));

    nums = { 4,5,6,7,0,1,2 };
    assert(-1 == s.search(nums, 3));

    nums = { 1 };
    assert(-1 == s.search(nums, 0));

    return 0;
}
