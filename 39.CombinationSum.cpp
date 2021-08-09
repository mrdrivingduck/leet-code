/**
 * @author Mr Dk.
 * @version 2021/08/09
 */

/*
    Given an array of distinct integers candidates and a target integer
    target, return a list of all unique combinations of candidates where
    the chosen numbers sum to target. You may return the combinations in
    any order.

    The same number may be chosen from candidates an unlimited number of
    times. Two combinations are unique if the frequency of at least one of
    the chosen numbers is different.

    It is guaranteed that the number of unique combinations that sum up to
    target is less than 150 combinations for the given input. 

    Example 1:
        Input: candidates = [2,3,6,7], target = 7
        Output: [[2,2,3],[7]]
        Explanation:
            2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be
            used multiple times.
            7 is a candidate, and 7 = 7.
            These are the only two combinations.

    Example 2:
        Input: candidates = [2,3,5], target = 8
        Output: [[2,2,2,2],[2,3,3],[3,5]]

    Example 3:
        Input: candidates = [2], target = 1
        Output: []

    Example 4:
        Input: candidates = [1], target = 1
        Output: [[1]]

    Example 5:
        Input: candidates = [1], target = 2
        Output: [[1,1]]

    Constraints:
        1 <= candidates.length <= 30
        1 <= candidates[i] <= 200
        All elements of candidates are distinct.
        1 <= target <= 500

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/combination-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    回溯。每轮回溯可以使用同一个元素。维护当前序列以及序列的和。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
private:
    void dfs(vector<int>& candidates,
             vector<vector<int>> &all, vector<int> &seq,
             size_t cur, int &sum, int &target) {
        for (size_t i = cur; i < candidates.size(); i++) {
            if (sum + candidates[i] < target) {
                seq.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates, all, seq, i, sum, target);
                sum -= candidates[i];
                seq.pop_back();
            } else if (sum + candidates[i] == target) {
                seq.push_back(candidates[i]);
                all.push_back(seq);
                seq.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> all;
        vector<int> seq;
        int sum = 0;

        dfs(candidates, all, seq, 0, sum, target);

        return all;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> comb;
    vector<int> candidates;

    comb = { { 2,2,3 }, { 7 } };
    candidates = { 2,3,6,7 };
    assert(comb == s.combinationSum(candidates, 7));

    comb = { { 2,2,2,2 }, { 2,3,3 }, { 3,5 } };
    candidates = { 2,3,5 };
    assert(comb == s.combinationSum(candidates, 8));

    comb = { };
    candidates = { 2 };
    assert(comb == s.combinationSum(candidates, 1));

    comb = { { 1 } };
    candidates = { 1 };
    assert(comb == s.combinationSum(candidates, 1));

    comb = { { 1,1 } };
    candidates = { 1 };
    assert(comb == s.combinationSum(candidates, 2));
    
    return 0;
}
