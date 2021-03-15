/**
 * @author Mr DK.
 * @version 2021/03/13
 */

/*
    Implement strStr().

    Return the index of the first occurrence of needle in haystack,
    or -1 if needle is not part of haystack.

    Clarification:
        What should we return when needle is an empty string? This is
        a great question to ask during an interview.

    For the purpose of this problem, we will return 0 when needle is
    an empty string. This is consistent to C's strstr() and Java's indexOf(). 

    Example 1:
        Input: haystack = "hello", needle = "ll"
        Output: 2
        
    Example 2:
        Input: haystack = "aaaaa", needle = "bba"
        Output: -1

    Example 3:
        Input: haystack = "", needle = ""
        Output: 0

    Constraints:
        0 <= haystack.length, needle.length <= 5 * 104
        haystack and needle consist of only lower-case English characters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/implement-strstr
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    KMP 算法的实现。
    https://mrdrivingduck.github.io/blog/#/markdown?repo=notes&path=Algorithm%2FAlgorithm%20KMP.md
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
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        vector<int> next(needle.length(), -1);
        int i = 0;
        int j = -1;
        while (i < (int) needle.length() - 1) {
            if (j == -1 || needle[i] == needle[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }

        i = 0;
        j = 0;
        while (i < (int) haystack.length() && j < (int) needle.length()) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j == (int) needle.length()) {
            return i - needle.length();
        }

        return -1;
    }
};

int main()
{
    Solution s;

    assert(-1 == s.strStr("baabbbbababbbabab", "abbab"));

    assert(4 == s.strStr("aabaaabaaac", "aabaaac"));

    assert(11 == s.strStr("ABCDABEABCDABCDABD", "ABCDABD"));

    assert(2 == s.strStr("hello", "ll"));

    assert(-1 == s.strStr("aaaaa", "bba"));

    assert(0 == s.strStr("", ""));

    return 0;
}
