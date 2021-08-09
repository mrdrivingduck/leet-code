/**
 * @author Mr Dk.
 * @version 2021/08/09
 */

/*
    Given a collection of candidate numbers (candidates) and a target number
    (target), find all unique combinations in candidates where the candidate
    numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations. 

    Example 1:
        Input: candidates = [10,1,2,7,6,1,5], target = 8
        Output: 
            [
                [1,1,6],
                [1,2,5],
                [1,7],
                [2,6]
            ]

    Example 2:
        Input: candidates = [2,5,2,1,2], target = 5
        Output: 
            [
                [1,2,2],
                [5]
            ]

    Constraints:
        1 <= candidates.length <= 100
        1 <= candidates[i] <= 50
        1 <= target <= 30

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/combination-sum-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    回溯。在每轮回溯中，值相等的元素只能使用一次；在不同轮回溯中，值相等的元素
    可以使用多次。同样，维护当前序列以及序列的和。

    为了方便过滤值相等的元素，先对输入序列进行排序。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
private:
    void dfs(vector<int>& candidates,
             vector<vector<int>> &all, vector<int> &seq,
             size_t cur, int &sum, int &target) {
        size_t i = cur;
        while (i < candidates.size()) {
            if (sum + candidates[i] < target) {
                seq.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates, all, seq, i + 1, sum, target);
                sum -= candidates[i];
                seq.pop_back();
            } else if (sum + candidates[i] == target) {
                seq.push_back(candidates[i]);
                all.push_back(seq);
                seq.pop_back();
            }
            
            int old = candidates[i];
            while (++i < candidates.size() && candidates[i] == old) {
                ;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> all;
        vector<int> seq;
        int sum = 0;
        std::sort(candidates.begin(), candidates.end());

        dfs(candidates, all, seq, 0, sum, target);

        return all;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> comb;
    vector<int> candidates;

    comb = { { 1,1,6 }, { 1,2,5 }, { 1,7 }, { 2,6 } };
    candidates = { 10,1,2,7,6,1,5 };
    assert(comb == s.combinationSum2(candidates, 8));

    comb = { { 1,2,2 }, { 5 } };
    candidates = { 2,5,2,1,2 };
    assert(comb == s.combinationSum2(candidates, 5));
    
    return 0;
}
