/**
 * @author Mr Dk.
 * @version 2021/03/17
 */

/*
    Given two strings s and t, return the number of distinct subsequences
    of s which equals t.

    A string's subsequence is a new string formed from the original string
    by deleting some (can be none) of the characters without disturbing
    the remaining characters' relative positions. (i.e., "ACE" is a
    subsequence of "ABCDE" while "AEC" is not).

    It is guaranteed the answer fits on a 32-bit signed integer. 

    Example 1:
        Input: s = "rabbbit", t = "rabbit"
        Output: 3
        Explanation:
            As shown below, there are 3 ways you can generate "rabbit" from S.
            rabbbit
            rabbbit
            rabbbit

    Example 2:
        Input: s = "babgbag", t = "bag"
        Output: 5
        Explanation:
            As shown below, there are 5 ways you can generate "bag" from S.
            babgbag
            babgbag
            babgbag
            babgbag
            babgbag

    Constraints:
        0 <= s.length, t.length <= 1000
        s and t consist of English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/distinct-subsequences
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
      '' b a b g b a g → (j)
    '' 1 1 1 1 1 1 1 1
     b 0 1 1 2 2 3 3 3
     a 0 0 1 1 1 1 4 4
     g 0 0 0 0 1 1 1 5
     ↓
    (i)

    初始条件：
        1. 如果模式串为空，那么空模式串是任何序列的子序列，所以子序列个数为 1
        2. 如果被匹配串为空，那么除了空串，任何模式串都无法成为被匹配串的子序列，个数为 0

    每当被匹配串的长度 + 1 时，其相对于模式串的子序列来自于两个方面：
        1. 当前已经与模式串匹配的子序列个数
        2. 新添加的字符与模式串字符匹配后的子序列个数

    以被匹配串 babgb(a) 与模式串 b(a) 的匹配为例，子序列个数来自于：
        1. babgb 与 ba 已经匹配上的子序列个数 (1 个)
            (相当于只把 a 加入被匹配串中，但不与模式串匹配)
        2. babgb 与 b 已经匹配上的子序列个数 (3 个)
            (相当于把 a 这个字符分别加入到两个串中，并使两个串匹配)
    
    综上，得到状态转移方程：
        d[i][j] = d[i - 1][j - 1] + d[i][j - 1]
    其中，当两个字符串的最后一个字符不匹配时，d[i - 1][j - 1] 这一项不应当
    被考虑，因为分别将字符加入两个串以后，并不能使两个串匹配，也就是：
        d[i][j] = d[i][j - 1];
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
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.length() + 1, vector<int>(s.length() + 1));

        for (size_t i = 1; i < dp.size(); i++) {
            dp[i][0] = 0;
        }
        for (size_t j = 0; j < dp[0].size(); j++) {
            dp[0][j] = 1;
        }

        for (size_t i = 1; i < dp.size(); i++) {
            for (size_t j = 1; j < dp[i].size(); j++) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[t.length()][s.length()];
    }
};

int main()
{
    Solution s;
    
    assert(3 == s.numDistinct("rabbbit", "rabbit"));

    assert(5 == s.numDistinct("babgbag", "bag"));
    
    return 0;
}
