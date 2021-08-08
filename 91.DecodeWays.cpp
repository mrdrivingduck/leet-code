/**
 * @author Mr Dk.
 * @version 2021/08/08
 */

/*
    A message containing letters from A-Z can be encoded into numbers using
    the following mapping:

    'A' -> "1"
    'B' -> "2"
    ...
    'Z' -> "26"

    To decode an encoded message, all the digits must be grouped then mapped
    back into letters using the reverse of the mapping above (there may be
    multiple ways). For example, "11106" can be mapped into:

    "AAJF" with the grouping (1 1 10 6)
    "KJF" with the grouping (11 10 6)

    Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
    into 'F' since "6" is different from "06".

    Given a string s containing only digits, return the number of ways to
    decode it.

    The answer is guaranteed to fit in a 32-bit integer. 

    Example 1:
        Input: s = "12"
        Output: 2
        Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

    Example 2:
        Input: s = "226"
        Output: 3
        Explanation:
            "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF"
            (2 2 6).

    Example 3:
        Input: s = "0"
        Output: 0
        Explanation:
            There is no character that is mapped to a number starting with 0.
            The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20",
            neither of which start with 0. Hence, there are no valid ways to
            decode this since all digits need to be mapped.

    Example 4:
        Input: s = "06"
        Output: 0
        Explanation:
            "06" cannot be mapped to "F" because of the leading zero ("6" is
            different from "06").

    Constraints:
        1 <= s.length <= 100
        s contains only digits and may contain leading zero(s).

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/decode-ways
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    深度优先？不行，超时了。采用动态规划。
    如果把当前数字作为一个独立的数字来看，那么累加 (长度 - 1) 子串的可能性个数。
    如果把当前数字与前一个数字作为整体来看 (构成 1-26)，那么累加 (长度 - 2) 子串
    的可能性个数。
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
    int numDecodings(string s) {
        vector<int> p(s.length() + 1, 0);
        p[0] = 1;
        p[1] = s[0] == '0' ? 0 : 1;

        for (size_t i = 1; i < s.length(); i++) {
            if ((s[i - 1] == '1' && s[i] >= '0' && s[i] <= '9') ||
                (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                p[i + 1] += p[i - 1];
            }
            if (s[i] >= '1' && s[i] <= '9') {
                p[i + 1] += p[i];
            }
        }

        return p[s.length()];
    }
};

int main()
{
    Solution s;

    assert(2 == s.numDecodings("12"));

    assert(3 == s.numDecodings("226"));

    assert(0 == s.numDecodings("0"));

    assert(0 == s.numDecodings("06"));

    assert(1 == s.numDecodings("10"));

    return 0;
}
