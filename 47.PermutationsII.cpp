/**
 * @author Mr Dk.
 * @version 2021/08/10
 */

/*
    Given a collection of numbers, nums, that might contain duplicates,
    return all possible unique permutations in any order.

    Example 1:
        Input: nums = [1,1,2]
        Output:
            [[1,1,2],
            [1,2,1],
            [2,1,1]]

    Example 2:
        Input: nums = [1,2,3]
        Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Constraints:
        1 <= nums.length <= 8
        -10 <= nums[i] <= 10

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/permutations-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    从右区间选出一个不重复的数字后，加入左区间，然后递归深度 + 1。
    在递归之前，需要将新的右区间重新排序。
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
        if (index == nums.size() - 1) {
            total.push_back(nums);
            return;
        }
        
        size_t i = index;
        while (i < nums.size()) {
            std::swap(nums[index], nums[i]);
            
            vector<int> cp(nums);
            std::sort(cp.begin() + index + 1, cp.end());
            dfs(total, cp, index + 1);
            
            std::swap(nums[index], nums[i]);

            size_t j = i + 1;
            while (j < nums.size() && nums[j] == nums[i]) {
                j++;
            }
            i = j;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> total;
        std::sort(nums.begin(), nums.end());
        dfs(total, nums, 0);
        return total;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<vector<int>> answer;

    nums = { 1,1,2 };
    answer = {
        { 1,1,2 },
        { 1,2,1 },
        { 2,1,1 }
    };
    assert(answer == s.permuteUnique(nums));

    nums = { 1,2,3 };
    answer = {
        { 1,2,3 },
        { 1,3,2 },
        { 2,1,3 },
        { 2,3,1 },
        { 3,1,2 },
        { 3,2,1 }
    };
    assert(answer == s.permuteUnique(nums));

    return 0;
}
