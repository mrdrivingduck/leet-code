/**
 * @author Mr Dk.
 * @version 2021/02/05
 */

/*
    You are given two strings s and t of the same length. You want to change
    s to t. Changing the i-th character of s to i-th character of t costs
    |s[i] - t[i]| that is, the absolute difference between the ASCII values
    of the characters.

    You are also given an integer maxCost.

    Return the maximum length of a substring of s that can be changed to be
    the same as the corresponding substring of twith a cost less than or equal
    to maxCost.

    If there is no substring from s that can be changed to its corresponding
    substring from t, return 0. 

    Example 1:
        Input: s = "abcd", t = "bcdf", maxCost = 3
        Output: 3
        Explanation:
            "abc" of s can change to "bcd". That costs 3, so the maximum
            length is 3.

    Example 2:
        Input: s = "abcd", t = "cdef", maxCost = 3
        Output: 1
        Explanation:
            Each character in s costs 2 to change to charactor in t, so the
            maximum length is 1.

    Example 3:
        Input: s = "abcd", t = "acde", maxCost = 0
        Output: 1
        Explanation: You can't make any change, so the maximum length is 1.

    Constraints:
        1 <= s.length, t.length <= 10^5
        0 <= maxCost <= 10^6
        s and t only contain lower case English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/get-equal-substrings-within-budget
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    滑动窗口。累加窗口内字符串的 cost。如果没有超出 maxCost，就更新最长的子串长度；
    如果超出了 maxCost，那么窗口左边界右移。
 */

#include <cassert>

#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int right = 0;
        int cost = 0;
        int max = 0;

        while (right < (int) t.length()) {
            cost += abs(s[right] - t[right]);

            if (cost <= maxCost) {
                max = std::max(max, right - left + 1);
            } else {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            right++;
        }

        return max;
    }
};

int main()
{
    Solution s;
    
    assert(3 == s.equalSubstring("abcd", "bcdf", 3));

    assert(1 == s.equalSubstring("abcd", "cdef", 3));

    assert(1 == s.equalSubstring("abcd", "acde", 0));

    return 0;
}
