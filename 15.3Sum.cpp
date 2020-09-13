/**
 * @author Mr Dk.
 * @version 2020/09/13
 */

/*
    Given an array nums of n integers, are there elements a, b, c in nums
    such that a + b + c = 0? Find all unique triplets in the array which
    gives the sum of zero.

    Notice that the solution set must not contain duplicate triplets.

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Example 2:

    Input: nums = []
    Output: []
    Example 3:

    Input: nums = [0]
    Output: []
     
    Constraints:

    0 <= nums.length <= 3000
    -105 <= nums[i] <= 105

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/3sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    双指针法，一开始被我用错了。外层循环定死内层循环的初始条件，且单方向迭代；
    内层循环利用双端指针进行双方向迭代。同时需要跳过重复的元素，还要尽可能地 early exit。

    while 循环比 for 循环快很多，但容易漏条件。while 循环中的条件包含：
        1. for 循环的终止条件
        2. for 循环体内的部分过滤条件
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arr_list;

        if (nums.size() < 3) {
            return arr_list;
        }

        sort(nums.begin(), nums.end());

        int left_p = 0;
        while (left_p < nums.size() && nums[left_p] <= 0) {

            if (nums[left_p] > 0) {
                break;
            }

            int left = left_p + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left_p] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> res = { nums[left_p], nums[left], nums[right] };
                    cout << nums[left_p] << " " << nums[left] << " " << nums[right] << endl;
                    arr_list.push_back(res);
                    left = find_next(nums, left, false);
                    right = find_next(nums, right, true);
                } else if (sum > 0) {
                    right = find_next(nums, right, true);
                } else {
                    left = find_next(nums, left, false);
                }
            }

            left_p = find_next(nums, left_p, false);
        }

        return arr_list;
    }

private:
    int find_next(vector<int>& nums, int current, bool left) {
        int i = left ? current - 1 : current + 1;
        if (i < 0 || i >= nums.size()) {
            return i;
        }
        while (i >= 0 && i < nums.size() && nums[i] == nums[current]) {
            if (left) {
                i--;
            } else {
                i++;
            }
        }

        return i;
    }
};

int main()
{
    // vector<int> list = { -1,0,1,2,-1,-4 };
    // vector<int> list = { 0 };
    // vector<int> list = { };
    // vector<int> list = { 0, 0 };
    vector<int> list = { 0, 0, 0 };
    Solution s;
    s.threeSum(list);
    return 0;
}