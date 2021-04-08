/**
 * @author Mr Dk.
 * @version 2021/04/08
 */

/*
    Suppose an array of length n sorted in ascending order is rotated
    between 1 and n times. For example, the array nums = [0,1,2,4,5,6,
    7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.

    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time
    results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

    Given the sorted rotated array nums of unique elements, return the
    minimum element of this array. 

    Example 1:
        Input: nums = [3,4,5,1,2]
        Output: 1
        Explanation: The original array was [1,2,3,4,5] rotated 3 times.

    Example 2:
        Input: nums = [4,5,6,7,0,1,2]
        Output: 0
        Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

    Example 3:
        Input: nums = [11,13,15,17]
        Output: 11
        Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 

    Constraints:
        n == nums.length
        1 <= n <= 5000
        -5000 <= nums[i] <= 5000
        All the integers of nums are unique.
        nums is sorted and rotated between 1 and n times.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    找到下降元素，与开头元素比较即可。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums.front();
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                min = std::min(nums[i + 1], min);
            }
        }
        return min;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 3,4,5,1,2 };
    assert(1 == s.findMin(nums));

    nums = { 4,5,6,7,0,1,2 };
    assert(0 == s.findMin(nums));

    nums = { 11,13,15,17 };
    assert(11 == s.findMin(nums));

    return 0;
}
