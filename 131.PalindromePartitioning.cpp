/**
 * @author Mr Dk.
 * @version 2021/03/07
 */

/*
    Given a string s, partition s such that every substring of the partition
    is a palindrome. Return all possible palindrome partitioning of s.

    A palindrome string is a string that reads the same backward as forward. 

    Example 1:
        Input: s = "aab"
        Output: [["a","a","b"],["aa","b"]]

    Example 2:
        Input: s = "a"
        Output: [["a"]]

    Constraints:
        1 <= s.length <= 16
        s contains only lowercase English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/palindrome-partitioning
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    深度优先搜素、回溯。不断将字符串缩短，直到长度为 0 时，产生一个结果。
    其中，判断是否为回文串可以用动态规划来做。维护一个上三角矩阵，对角线
    元素全都为 1，按对角线顺序填满矩阵。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {

    bool is_palindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void dfs(vector<vector<string>> &splits, vector<string> &traces, string &s, int start) {
        for (size_t i = start; i < s.length(); i++) {
            if (s[i] == s[start] && is_palindrome(s, start, i)) {
                traces.push_back(s.substr(start, i - start + 1));
                if (i + 1 < s.length()) {
                    dfs(splits, traces, s, i + 1);
                } else {
                    splits.push_back(traces);
                }
                traces.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> splits;
        vector<string> traces;
        dfs(splits, traces, s, 0);
        return splits;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> result;

    result = { { "a", "a", "b" }, { "aa", "b" } };
    assert(result == s.partition("aab"));

    result = { { "a" } };
    assert(result == s.partition("a"));

    return 0;
}
