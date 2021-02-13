/**
 * @author Mr Dk.
 * @version 2021/02/13
 */

/*
    Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
    some elements appear twice and others appear once.

    Find all the elements of [1, n] inclusive that do not appear in
    this array.

    Could you do it without extra space and in O(n) runtime? You may
    assume the returned list does not count as extra space.

    Example:
        Input:
            [4,3,2,7,8,2,3,1]
        Output:
            [5,6]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    直接使用数组本身作为 hash 表。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            int temp = nums[i] - 1;
            while (temp >= (int) nums.size()) {
                temp -= nums.size();
            }

            nums[temp] += nums.size();
        }

        vector<int> result;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] <= (int) nums.size()) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> result;

    nums = { 4,3,2,7,8,2,3,1 };
    result = { 5,6 };
    assert(result == s.findDisappearedNumbers(nums));

    return 0;
}
