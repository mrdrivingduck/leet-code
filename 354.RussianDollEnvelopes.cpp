/**
 * @author Mr Dk.
 * @version 2021/03/04
 */

/*
    You have a number of envelopes with widths and heights given as a
    pair of integers (w, h). One envelope can fit into another if and
    only if both the width and height of one envelope is greater than
    the width and height of the other envelope.

    What is the maximum number of envelopes can you Russian doll?
    (put one inside other)

    Note:
        Rotation is not allowed.

    Example:
        Input: [[5,4],[6,4],[6,7],[2,3]]
        Output: 3 
        Explanation:
            The maximum number of envelopes you can Russian doll is 3
            ([2,3] => [5,4] => [6,7]).

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/russian-doll-envelopes
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    先根据信封长度升序排序，长度相同的根据宽度降序排序。
    根据宽度序列，通过动态规划找出宽度序列的最长上升子序列。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

bool comp(vector<int> &v1, vector<int> &v2) {
    if (v1[0] == v2[0]) {
        return v1[1] > v2[1];
    }
    return v1[0] < v2[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (!envelopes.size()) {
            return 0;
        }

        std::sort(envelopes.begin(), envelopes.end(), comp);

        vector<int> dp(envelopes.size(), 1);
        int max = 1;
        for (size_t i = 1; i < envelopes.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[j][0] == envelopes[i][0]) {
                    continue;
                } else if (envelopes[j][1] < envelopes[i][1] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }

            if (dp[i] > max) {
                max = dp[i];
            }
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> envelopes;

    envelopes = {
        {2,100},
        {3,200},
        {4,300},
        {5,500},
        {5,400},
        {5,250},
        {6,370},
        {6,360},
        {7,380}
    };
    assert(5 == s.maxEnvelopes(envelopes));

    envelopes = {
        { 5,4 },
        { 6,4 },
        { 6,7 },
        { 2,3 }
    };
    assert(3 == s.maxEnvelopes(envelopes));

    return 0;
}
