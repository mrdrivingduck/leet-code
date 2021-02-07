/**
 * @author Mr Dk.
 * @version 2021/02/07
 */

/*
    Given an array nums with n integers, your task is to check if it
    could become non-decreasing by modifying at most one element.

    We define an array is non-decreasing if nums[i] <= nums[i + 1]
    holds for every i (0-based) such that (0 <= i <= n - 2). 

    Example 1:
        Input: nums = [4,2,3]
        Output: true
        Explanation:
            You could modify the first 4 to 1 to get a non-decreasing
            array.

    Example 2:
        Input: nums = [4,2,1]
        Output: false
        Explanation:
            You can't get a non-decreasing array by modify at most
            one element.

    Constraints:
        n == nums.length
        1 <= n <= 104
        -105 <= nums[i] <= 105

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/non-decreasing-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <cassert>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int chance = 1;
        for (int i = 0; i < (int) nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (i - 1 >= 0 && nums[i - 1] <= nums[i + 1]) {
                    nums[i] = nums[i - 1];
                } else if (i - 1 >= 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                }

                chance--;

                if (chance < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { -1,4,2,3 };
    assert(true == s.checkPossibility(nums));

    nums = { 5,7,1,8 };
    assert(true == s.checkPossibility(nums));

    nums = { 3,4,2,3 };
    assert(false == s.checkPossibility(nums));

    nums = { 4,2,3 };
    assert(true == s.checkPossibility(nums));

    nums = { 4,2,1 };
    assert(false == s.checkPossibility(nums));

    return 0;
}
