/**
 * @author Mr Dk.
 * @version 2021/03/11
 */

/*
    Given two strings word1 and word2, return the minimum number of
    operations required to convert word1 to word2.

    You have the following three operations permitted on a word:
        Insert a character
        Delete a character
        Replace a character

    Example 1:
        Input: word1 = "horse", word2 = "ros"
        Output: 3
        Explanation: 
            horse -> rorse (replace 'h' with 'r')
            rorse -> rose (remove 'r')
            rose -> ros (remove 'e')

    Example 2:
        Input: word1 = "intention", word2 = "execution"
        Output: 5
        Explanation: 
            intention -> inention (remove 't')
            inention -> enention (replace 'i' with 'e')
            enention -> exention (replace 'n' with 'x')
            exention -> exection (replace 'n' with 'c')
            exection -> execution (insert 'u')

    Constraints:
        0 <= word1.length, word2.length <= 500
        word1 and word2 consist of lowercase English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/edit-distance
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    在一个字符串中删除一个字符等价于在另一个字符串中添加一个字符。
    所以等价的操作只有两种：添加和替换。
    可以将两个字符串从小到大搜素。假设两个字符串为 abbc 和 cb：
        1. abb(c) <-> c(b)：一次替换
        2. abb(c) <-> cb：一次增加
        3. abbc <-> c(b)：一次增加
    取它们三者的最小值，并 + 1 即可。
    如果在两个字符串中新添加的字符相同，例如 abb(c) <-> c(c) 的情况，
    可以等价于 abb <-> c 的情况 (因为对新添加的字符无需进行任何修改)。
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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length()));
        if (word1.empty() || word2.empty()) {
            return std::max(word1.length(), word2.length());
        }

        dp[0][0] = word1[0] == word2[0] ? 0 : 1;
        bool used = word1[0] == word2[0] ? true : false;
        for (size_t i = 1; i < word1.length(); i++) {
            if (word1[i] == word2[0] && !used) {
                dp[i][0] = dp[i - 1][0];
                used = true;
            } else {
                dp[i][0] = dp[i - 1][0] + 1;
            }
        }
        used = word1[0] == word2[0] ? true : false;
        for (size_t i = 1; i < word2.length(); i++) {
            if (word2[i] == word1[0] && !used) {
                dp[0][i] = dp[0][i - 1];
                used = true;
            } else {
                dp[0][i] = dp[0][i - 1] + 1;
            }
        }

        for (size_t i = 1; i < word1.length(); i++) {
            for (size_t j = 1; j < word2.length(); j++) {
                if (word1[i] == word2[j]) {
                    // abbc <-> cc
                    // 1. abbc <-> c(c): [i][j] = [i][j - 1] + 1 (insert)
                    // 2. abb(c) <-> cc: [i][j] = [i - 1][j] + 1 (insert)
                    // 3. abb(c) <-> c(c): [i][j] = [i - 1][j - 1] (NOP)
                    dp[i][j] = std::min(dp[i - 1][j - 1], 1 + std::min(dp[i][j - 1], dp[i - 1][j]));
                } else {
                    // abbc <-> cb
                    // 1. abbc <-> c(b): [i][j] = [i][j - 1] + 1 (insert)
                    // 2. abb(c) <-> cb: [i][j] = [i - 1][j] + 1 (insert)
                    // 3. abb(c) <-> c(b): [i][j] = [i - 1][j - 1] + 1 (replace)
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }

        // for (size_t i = 0; i < word1.length(); i++) {
        //     for (size_t j = 0; j < word2.length(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[word1.length() - 1][word2.length() - 1];
    }
};

int main()
{
    Solution s;
    
    assert(3 == s.minDistance("horse", "ros"));

    assert(4 == s.minDistance("extension", "execution"));

    assert(5 == s.minDistance("intention", "execution"));

    return 0;
}
