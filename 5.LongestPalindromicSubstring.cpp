/**
 * @author Mr Dk.
 * @version 2019.08.06
 */

/*
    Given a string s, find the longest palindromic substring in s. 
    You may assume that the maximum length of s is 1000.

    Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

    Example 2:

    Input: "cbbd"
    Output: "bb"

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-palindromic-substring
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    动态规划 - 右上三角矩阵
    [i][j] 分别代表字符串的开始字符和结束字符
    矩阵值为 -1 代表不是回文，否则代表回文的长度

    [0][0] [0][1] [0][2] [0][3]
           [1][1] [1][2] [1][3]
                  [2][2] [2][3]
                         [3][3]

    [i][i] 对角线被初始化为 1
    [i][i+1] 对角线被初始化为 s[i] == s[i+1] ? 2 : -1
    随后，依次填满对角线，直至最右上角
    s[i][j] = 
        s[i+1][j-1] != -1 && s[i] == s[j] ?               -> 除首尾指针以外是回文 
            i == j ? s[i+1][j-1] + 1 : s[i+1][j-1] + 2    -> 首尾指针重叠，回文长度 +1 / +2
            : -1                                          -> 不是回文

    同时，记录长度最大的回文和对应的首尾指针位置

    复杂度 O(n^2)，但我不想优化了 😌
 */

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::size_t;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return s;
        }

        int maxlen = 1;
        int maxi = 0;
        int maxj = 0;
        vector<vector<int> > matrix(s.length(), vector<int> (s.length(), -1));
        for (size_t i = 0; i < matrix.size(); i++) {
            matrix[i][i] = 1;
            if (i + 1 < matrix.size()) {
                if (s[i] == s[i + 1]) {
                    matrix[i][i + 1] = 2;
                    if (matrix[i][i + 1] > maxlen) {
                        maxlen = matrix[i][i + 1];
                        maxi = i;
                        maxj = i + 1;
                    }
                } else {
                    matrix[i][i + 1] = -1;
                }

            }
        }

        for (size_t j = 2; j < matrix.size(); j++) {
            for (size_t i = 0; j + i < matrix.size(); i++) {
                if (matrix[i + 1][j + i - 1] != -1 && s[i] == s[j + i]) {
                    if (i == j + i) {
                        matrix[i][j + i] = matrix[i + 1][j + i - 1] + 1;
                    } else {
                        matrix[i][j + i] = matrix[i + 1][j + i - 1] + 2;
                    }
                    if (matrix[i][j + i] > maxlen) {
                        maxlen = matrix[i][j + i];
                        maxi = i;
                        maxj = j + i;
                    }
                } else {
                    matrix[i][j + i] = -1;
                }
            }
        }

        // for (int i = 0; i < matrix.size(); i++) {
        //     for (int j = 0; j < matrix.size(); j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << maxi << endl;
        // cout << maxj << endl;

        return s.substr(maxi, maxj - maxi + 1);
    }
};

int main() {

    Solution solution;
    cout << solution.longestPalindrome("") << endl;
    cout << solution.longestPalindrome("ac") << endl;
    cout << solution.longestPalindrome("abb") << endl;
    cout << solution.longestPalindrome("abba") << endl;
    cout << solution.longestPalindrome("abbbccbb") << endl;
    cout << solution.longestPalindrome("abcda") << endl;

    return 0;
}
