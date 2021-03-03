/**
 * @author Mr Dk.
 * @version 2021/03/03

/*
    Given two strings text1 and text2, return the length of their
    longest common subsequence.

    A subsequence of a string is a new string generated from the
    original string with some characters(can be none) deleted without
    changing the relative order of the remaining characters. (eg, "ace"
    is a subsequence of "abcde" while "aec" is not). A common
    subsequence of two strings is a subsequence that is common to both
    strings. 

    If there is no common subsequence, return 0.

    Example 1:
        Input: text1 = "abcde", text2 = "ace" 
        Output: 3  
        Explanation:
            The longest common subsequence is "ace" and its length is 3.

    Example 2:
        Input: text1 = "abc", text2 = "abc"
        Output: 3
        Explanation:
            The longest common subsequence is "abc" and its length is 3.

    Example 3:
        Input: text1 = "abc", text2 = "def"
        Output: 0
        Explanation:
            There is no such common subsequence, so the result is 0.

    Constraints:
        1 <= text1.length <= 1000
        1 <= text2.length <= 1000
        The input strings consist of lowercase English characters only.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-common-subsequence
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    动态规划，用二维数组表示两个字符串的子串的最小公共子序列。递推公式：
    seq[i][j] = {
        max{ seq[i - 1][j], seq[i][j - 1] }, IF text1[i] != text2[j]
        seq[i][j] = seq[i - 1][j - 1] + 1,   IF text1[i] == text2[j]
    }
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
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> seq(text1.length(), vector<int>(text2.length()));

        seq[0][0] = text1[0] == text2[0];

        for (size_t i = 1; i < text2.length(); i++) {
            if (text1[0] == text2[i]) {
                seq[0][i] = 1;
            } else {
                seq[0][i] = seq[0][i - 1];
            }
        }

        for (size_t i = 1; i < text1.length(); i++) {
            if (text1[i] == text2[0]) {
                seq[i][0] = 1;
            } else {
                seq[i][0] = seq[i - 1][0];
            }
        }

        // for (size_t i = 0; i < text1.length(); i++) {
        //     for (size_t j = 0; j < text2.length(); j++) {
        //         cout << seq[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for (size_t i = 1; i < text1.length(); i++) {
            for (size_t j = 1; j < text2.length(); j++) {
                if (text1[i] == text2[j]) {
                    seq[i][j] = seq[i - 1][j - 1] + 1;
                } else {
                    seq[i][j] = std::max(seq[i - 1][j], seq[i][j - 1]);
                }
            }
        }

        return seq[text1.length() - 1][text2.length() - 1];
    }
};

int main()
{
    Solution s;

    assert(2 == s.longestCommonSubsequence("aaaaa", "aa"));

    assert(1 == s.longestCommonSubsequence("bsbininm", "jmjkbkjkv"));

    assert(2 == s.longestCommonSubsequence("ezupkr", "ubmrapg"));
    
    assert(3 == s.longestCommonSubsequence("abcde", "ace"));

    assert(3 == s.longestCommonSubsequence("abc", "abc"));

    assert(0 == s.longestCommonSubsequence("abc", "def"));

    return 0;
}
