/**
 * @author Mr Dk.
 * @version 2021/04/07
 */

/*
    There is an integer array nums sorted in non-decreasing order (not
    necessarily with distinct values).

    Before being passed to your function, nums is rotated at an unknown
    pivot index k (0 <= k < nums.length) such that the resulting array
    is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
    nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be
    rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

    Given the array nums after the rotation and an integer target, return
    true if target is in nums, or false if it is not in nums. 

    Example 1:
        Input: nums = [2,5,6,0,0,1,2], target = 0
        Output: true

    Example 2:
        Input: nums = [2,5,6,0,0,1,2], target = 3
        Output: false

    Constraints:
        1 <= nums.length <= 5000
        -104 <= nums[i] <= 104
        nums is guaranteed to be rotated at some pivot.
        -104 <= target <= 104

    Follow up: This problem is the same as Search in Rotated Sorted Array,
    where nums may contain duplicates. Would this affect the runtime
    complexity? How and why?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    遍历找到分界点，然后以分界点为边界进行二分搜索。(我知道这不是最优解)
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
    bool search(vector<int>& nums, int target) {
        size_t i = 0;
        for (; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                break;
            }
        }

        if (nums[i] == target) {
            return true;
        }
        
        return std::binary_search(nums.begin(), nums.begin() + i, target) ||
                std::binary_search(nums.begin() + i + 1, nums.end(), target);
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 1,0,1,1,1 };
    assert(true == s.search(nums, 0));

    nums = { 2,5,6,0,0,1,2 };
    assert(true == s.search(nums, 0));

    nums = { 2,5,6,0,0,1,2 };
    assert(false == s.search(nums, 3));

    return 0;
}
