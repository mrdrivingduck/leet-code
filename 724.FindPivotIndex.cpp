/**
 * @author Mr Dk.
 * @version 2021/01/28
 */

/*
    Given an array of integers nums, write a method that returns the "pivot"
    index of this array.

    We define the pivot index as the index where the sum of all the numbers
    to the left of the index is equal to the sum of all the numbers to the
    right of the index.

    If no such index exists, we should return -1. If there are multiple pivot
    indexes, you should return the left-most pivot index. 

    Example 1:
        Input: nums = [1,7,3,6,5,6]
        Output: 3
        Explanation:
            The sum of the numbers to the left of index 3 (nums[3] = 6) is
            equal to the sum of numbers to the right of index 3.
            Also, 3 is the first index where this occurs.

    Example 2:
        Input: nums = [1,2,3]
        Output: -1
        Explanation:
            There is no index that satisfies the conditions in the problem
            statement.    

    Constraints:
        The length of nums will be in the range [0, 10000].
        Each element nums[i] will be an integer in the range [-1000, 1000].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/find-pivot-index
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    计算 pivot 左边和右边的和，将 pivot 从左向右向右移动，重新计算左右两边的和。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }

        int left = 0;
        int right = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            right += nums[i];
        }

        for (int i = 0; i < (int) nums.size(); i++) {
            if (left == right) {
                return i;
            }
            if (i == (int) nums.size() - 1) {
                break;
            }

            left += nums[i];
            right -= nums[i + 1];
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { -1,-1,-1,0,1,1 };
    assert(0 == s.pivotIndex(nums));

    nums = { 1,7,3,6,5,6 };
    assert(3 == s.pivotIndex(nums));

    nums = { 1,2,3 };
    assert(-1 == s.pivotIndex(nums));

    return 0;
}
