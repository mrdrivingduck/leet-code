/**
 * @author Mr Dk.
 * @version 2020/12/01
 */

/*
    Given an array of integers nums sorted in ascending order, find
    the starting and ending position of a given target value.

    If target is not found in the array, return [-1, -1].

    Follow up: Could you write an algorithm with O(log n) runtime
    complexity?

    Example 1:
        Input: nums = [5,7,7,8,8,10], target = 8
        Output: [3,4]

    Example 2:
        Input: nums = [5,7,7,8,8,10], target = 6
        Output: [-1,-1]

    Example 3:
        Input: nums = [], target = 0
        Output: [-1,-1]

    Constraints:
        0 <= nums.length <= 105
        -109 <= nums[i] <= 109
        nums is a non-decreasing array.
        -109 <= target <= 109

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    实现了 vector 版本和数组版本，vector 版本因效率较低而被注释。

    大致思想是二分查找。如果中间元素位于目标范围之外，则只需要在半边继续查找即可
    如果中间元素位于目标区间以内，则需要在两边分别查找边界，然后将区间合并。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::size_t;

class Solution {
// private:
//     vector<int> binary_search(vector<int> &nums, int target, int start, int end) {
//         // promise: start <= end!

//         int mid = (start + end) >> 1;

//         if (target < nums[mid] && start <= mid - 1) {
//             return binary_search(nums, target, start, mid - 1);
//         } else if (nums[mid] < target && mid + 1 <= end) {
//             return binary_search(nums, target, mid + 1, end);
//         } else if (nums[mid] == target) {
//             vector<int> pre, post;

//             if (start <= mid - 1 && nums[mid - 1] == target) {
//                 pre = binary_search(nums, target, start, mid - 1);
//             } else {
//                 pre = { mid, mid };
//             }

//             if (mid + 1 <= end && nums[mid + 1] == target) {
//                 post = binary_search(nums, target, mid + 1, end);
//             } else {
//                 post = { mid, mid };
//             }
            
//             return { pre[0], post[1] };
//         }

//         return { -1, -1 };
//     }

// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if (nums.size() > 0) {
//             return binary_search(nums, target, 0, nums.size() - 1);
//         } else {
//             return { -1, -1 };
//         }
//     }

private:
    void binary_search(vector<int> &nums, int target, int start, int end, int range[2]) {
        // promise: start <= end!

        int mid = (start + end) >> 1;

        if (target < nums[mid] && start <= mid - 1) {
            return binary_search(nums, target, start, mid - 1, range);
        } else if (nums[mid] < target && mid + 1 <= end) {
            return binary_search(nums, target, mid + 1, end, range);
        } else if (nums[mid] == target) {
            int temp_range[2];

            // left range
            if (start <= mid - 1 && nums[mid - 1] == target) {
                binary_search(nums, target, start, mid - 1, temp_range);
                range[0] = temp_range[0];
            } else {
                range[0] = mid;
            }

            // right range
            if (mid + 1 <= end && nums[mid + 1] == target) {
                binary_search(nums, target, mid + 1, end, temp_range);
                range[1] = temp_range[1];
            } else {
                range[1] = mid;
            }

            return;
        }

        // not found, or start > mid - 1 || mid + 1 > end
        range[0] = -1;
        range[1] = -1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int range[2] = { -1, -1 };
        if (nums.size() > 0) {
            binary_search(nums, target, 0, nums.size() - 1, range);
        }
        
        return vector<int> { range[0], range[1] };
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    
    nums = { 5,7,7,8,8,10 };
    nums = s.searchRange(nums, 8);
    cout << nums[0] << " " << nums[1] << endl;

    nums = { 5,7,7,8,8,10 };
    nums = s.searchRange(nums, 6);
    cout << nums[0] << " " << nums[1] << endl;

    nums = { 5,7,8,9,9,10 };
    nums = s.searchRange(nums, 8);
    cout << nums[0] << " " << nums[1] << endl;

    nums = { 5,7,8,8,9,10 };
    nums = s.searchRange(nums, 8);
    cout << nums[0] << " " << nums[1] << endl;

    nums = { 5,8,8,9,9,10 };
    nums = s.searchRange(nums, 8);
    cout << nums[0] << " " << nums[1] << endl;

    nums = { 5,8,8,8,9,10 };
    nums = s.searchRange(nums, 8);
    cout << nums[0] << " " << nums[1] << endl;

    nums = {  };
    nums = s.searchRange(nums, 8);
    cout << nums[0] << " " << nums[1] << endl;

    return 0;
}
