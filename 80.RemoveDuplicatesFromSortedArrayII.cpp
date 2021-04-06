/**
 * @author Mr Dk.
 * @version 2021/04/06
 */

/*
    Given a sorted array nums, remove the duplicates in-place such that
    duplicates appeared at most twice and return the new length.

    Do not allocate extra space for another array; you must do this by
    modifying the input array in-place with O(1) extra memory.

    Clarification:
        Confused why the returned value is an integer, but your answer is an array?

    Note that the input array is passed in by reference, which means a
    modification to the input array will be known to the caller.

    Internally you can think of this:

    // nums is passed in by reference. (i.e., without making a copy)
    int len = removeDuplicates(nums);

    // any modification to nums in your function would be known by the caller.
    // using the length returned by your function, it prints the first len elements.
    for (int i = 0; i < len; i++) {
        print(nums[i]);
    } 

    Example 1:
        Input: nums = [1,1,1,2,2,3]
        Output: 5, nums = [1,1,2,2,3]
        Explanation:
            Your function should return length = 5, with the first five
            elements of nums being 1, 1, 2, 2 and 3 respectively. It
            doesn't matter what you leave beyond the returned length.

    Example 2:
        Input: nums = [0,0,1,1,1,1,2,3,3]
        Output: 7, nums = [0,0,1,1,2,3,3]
        Explanation:
            Your function should return length = 7, with the first seven
            elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3
            respectively. It doesn't matter what values are set beyond
            the returned length.

    Constraints:
        1 <= nums.length <= 3 * 104
        -104 <= nums[i] <= 104
        nums is sorted in ascending order.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    快慢指针。将数组后面的元素向前挪。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int dup_count = 0;
        int size = nums.size();

        for (; fast < size;) {
            nums[slow++] = nums[fast++];
            if (fast < size) {
                if (nums[fast] != nums[fast - 1]) {
                    dup_count = 0;
                } else if (dup_count == 0) {
                    dup_count++;
                } else {
                    dup_count = 0;
                    int old = nums[fast];
                    while (++fast < size && nums[fast] == old) {
                        ;
                    }
                }
            }
        }

        nums.resize(slow);
        return slow;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> result;

    nums = { 1,1,1,2,2,3 };
    result = { 1,1,2,2,3 };
    assert(5 == s.removeDuplicates(nums));
    assert(result == nums);

    nums = { 0,0,1,1,1,1,2,3,3 };
    result = { 0,0,1,1,2,3,3 };
    assert(7 == s.removeDuplicates(nums));
    assert(result == nums);

    return 0;
}
