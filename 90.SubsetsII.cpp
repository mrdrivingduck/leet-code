/**
 * @author Mr Dk.
 * @version 2021/03/31
 */

/*
    Given an integer array nums that may contain duplicates, return all
    possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the
    solution in any order. 

    Example 1:
        Input: nums = [1,2,2]
        Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    Example 2:
        Input: nums = [0]
        Output: [[],[0]]

    Constraints:
        1 <= nums.length <= 10
        -10 <= nums[i] <= 10

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/subsets-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    用一个 multiset 维护所有可选元素。通过深度优先搜素，从 multiset
    中搜素元素并增加子集的长度。为了防止重复，每次从 multiset 选元素
    时，应当从第一个大于等于 subset 最后一个元素的元素开始选起，保证
    子集内的元素非严格单调递增。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::multiset;

class Solution {
    void dfs(vector<vector<int>> &subsets, vector<int> &subset, multiset<int> &remaining) {
        subsets.push_back(subset);

        if (remaining.empty()) {
            return;
        }

        int pre = subset.empty() ? INT32_MIN : subset[subset.size() - 1] - 1;
        multiset<int>::iterator iter;
        while ((iter = remaining.upper_bound(pre)) != remaining.end()) {
            pre = *iter; // previous maximum element
            subset.push_back(*iter);
            remaining.erase(iter);
            dfs(subsets, subset, remaining);
            remaining.insert(pre);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        multiset<int> remaining(nums.begin(), nums.end());

        dfs(subsets, subset, remaining);

        return subsets;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<vector<int>> subsets;

    nums = { 1,2,2 };
    subsets = {
        {  },
        { 1 },
        { 1,2 },
        { 1,2,2 },
        { 2 },
        { 2,2 },
    };
    assert(subsets == s.subsetsWithDup(nums));

    nums = { 0 };
    subsets = {
        {  },
        { 0 }
    };
    assert(subsets == s.subsetsWithDup(nums));

    return 0;
}
