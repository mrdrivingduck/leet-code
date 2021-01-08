/**
 * @author Mr Dk.
 * @version 2021/01/08
 */

/*
    Given an array, rotate the array to the right by k steps, where k is
    non-negative.

    Follow up:
        Try to come up as many solutions as you can, there are at least 3
        different ways to solve this problem.
        Could you do it in-place with O(1) extra space? 

    Example 1:
        Input: nums = [1,2,3,4,5,6,7], k = 3
        Output: [5,6,7,1,2,3,4]
        Explanation:
            rotate 1 steps to the right: [7,1,2,3,4,5,6]
            rotate 2 steps to the right: [6,7,1,2,3,4,5]
            rotate 3 steps to the right: [5,6,7,1,2,3,4]

    Example 2:
        Input: nums = [-1,-100,3,99], k = 2
        Output: [3,99,-1,-100]
        Explanation: 
            rotate 1 steps to the right: [99,-1,-100,3]
            rotate 2 steps to the right: [3,99,-1,-100]

    Constraints:
        1 <= nums.length <= 2 * 104
        -231 <= nums[i] <= 231 - 1
        0 <= k <= 105

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/rotate-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    先将整个数组逆置，然后按区间分别将部分数组逆置回来。
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
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> result;

    nums = { 1,2,3,4,5,6,7 };
    result = { 5,6,7,1,2,3,4 };
    s.rotate(nums, 3);
    assert(result == nums);

    nums = { -1,-100,3,99 };
    result = { 3,99,-1,-100 };
    s.rotate(nums, 2);
    assert(result == nums);

    return 0;
}
