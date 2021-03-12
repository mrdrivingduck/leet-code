/**
 * @author Mr Dk.
 * @version 2021/03/12
 */

/*
    Given an array nums of distinct integers, return all the possible
    permutations. You can return the answer in any order.

    Example 1:
        Input: nums = [1,2,3]
        Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Example 2:
        Input: nums = [0,1]
        Output: [[0,1],[1,0]]

    Example 3:
        Input: nums = [1]
        Output: [[1]]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/permutations
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    将数组分为左右两个区间，左区间为已填写的字符，右区间为未填写的字符。每次从
    右区间的字符中循环挑选一个添加到左区间的最后，然后递归到下一层 (方便回溯)。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
    void dfs(vector<vector<int>> &total, vector<int>& nums, size_t index) {
        if (index == nums.size()) {
            total.push_back(nums);
        }
        for (size_t i = index; i < nums.size(); i++) {
            int temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;

            dfs(total, nums, index + 1);

            temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> total;
        dfs(total, nums, 0);
        return total;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<vector<int>> answer;
    vector<vector<int>> result;

    nums = { 1,2,3 };
    answer = {
        { 1,2,3 },
        { 1,3,2 },
        { 2,1,3 },
        { 2,3,1 },
        { 3,1,2 },
        { 3,2,1 }
    };
    result = s.permute(nums);
    std::sort(result.begin(), result.end());
    assert(answer == result);

    return 0;
}
