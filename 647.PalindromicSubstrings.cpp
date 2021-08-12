/**
 * @author Mr Dk.
 * @version 2021/08/12
 */

/*
    Given a string s, return the number of palindromic substrings in it.
    A string is a palindrome when it reads the same backward as forward.
    A substring is a contiguous sequence of characters within the string.

    Example 1:
        Input: s = "abc"
        Output: 3
        Explanation: Three palindromic strings: "a", "b", "c".

    Example 2:
        Input: s = "aaa"
        Output: 6
        Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

    Constraints:
        1 <= s.length <= 1000
        s consists of lowercase English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/palindromic-substrings
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    同样使用最长回文字符串的思路，只是数组中不再需要记录具体的回文串长度。
    用一个二维数组的上三角表示 [i][j] 范围内是否为回文。初始化：
        1. 对角线全部为 true，因为每一个独立字符都是回文
        2. 连续两个相等字符肯定能构成回文

    然后依次填满上三角即可：
        m[i][j] = (s[i] == s[j] && m[i + 1][j - 1] == true) ?
                    true :
                    false;
    
    由于使用上三角，需要从下向上填充。因为如果从上向下填充的话，可能有的
    中间结果还没有被算出来。
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
    int countSubstrings(string s) {
        vector<vector<bool>> m(s.length(), vector<bool>(s.length(), false));
        int count = 0;

        for (size_t i = 0; i < s.length(); i++) {
            m[i][i] = true;
            count++;

            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                m[i][i + 1] = true; 
                count++;
            }
        }

        for (int i = s.length() - 2; i >= 0; i--) {
            for (size_t j = i + 2; j < s.length(); j++) {
                if (s[i] == s[j] && m[i + 1][j - 1]) {
                    m[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution s;

    assert(15 == s.countSubstrings("aaaaa"));

    assert(3 == s.countSubstrings("abc"));

    assert(6 == s.countSubstrings("aaa"));

    return 0;
}
