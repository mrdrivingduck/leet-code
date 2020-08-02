/**
 * @author Mr Dk.
 * @version 2020/08/02
 */

/*
    Implement atoi which converts a string to an integer.

    The function first discards as many whitespace characters as necessary
    until the first non-whitespace character is found. Then, starting from
    this character, takes an optional initial plus or minus sign followed
    by as many numerical digits as possible, and interprets them as a
    numerical value.

    The string can contain additional characters after those that form the
    integral number, which are ignored and have no effect on the behavior
    of this function.

    If the first sequence of non-whitespace characters in str is not a
    valid integral number, or if no such sequence exists because either
    str is empty or it contains only whitespace characters, no conversion
    is performed.

    If no valid conversion could be performed, a zero value is returned.

    Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store
    integers within the 32-bit signed integer range: [−231,  231 − 1].
    If the numerical value is out of the range of representable values,
    INT_MAX (231 − 1) or INT_MIN (−231) is returned.

    Example 1:

    Input: "42"
    Output: 42

    Example 2:

    Input: "   -42"
    Output: -42
    Explanation: The first non-whitespace character is '-', which is the minus sign.
                 Then take as many numerical digits as possible, which gets 42.
    Example 3:

    Input: "4193 with words"
    Output: 4193
    Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

    Example 4:

    Input: "words and 987"
    Output: 0
    Explanation: The first non-whitespace character is 'w', which is not a numerical 
                 digit or a +/- sign. Therefore no valid conversion could be performed.

    Example 5:

    Input: "-91283472332"
    Output: -2147483648
    Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
                 Thefore INT_MIN (−231) is returned.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/string-to-integer-atoi
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    第一反应使用编译原理的 DFA，但是实在是没必要。

    需要注意如果运算溢出会报 runtime 异常。为了防止溢出，可以通过与 INT_MIN 或 INT_MAX 相减或相除
    来作为判断条件，如果确认不会移除，再运行乘法或加法。
*/

#include <iostream>
#include <string>
#include <limits.h>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    int myAtoi(string str) {
        bool negative = false;
        int start_idx = 0;
        for (; start_idx < str.length(); start_idx++) {
            if (str[start_idx] == ' ') {
                continue;
            } else if (str[start_idx] == '-') {
                start_idx++;
                negative = true;
                break;
            } else if (str[start_idx] == '+') {
                start_idx++;
                // negative = false;
                break;
            } else if (str[start_idx] >= '0' && str[start_idx] <= '9') {
                break;
            } else {
                /* Other characters. */
                return 0;
            }
        }

        int value = 0;
        for (int i = start_idx; i < str.length(); i++) {
            if (str[i] < '0' || str[i] > '9') {
                return value;
            }

            if (negative) {
                if (value < (INT_MIN / 10)) {
                    return INT_MIN;
                }
                value *= 10;
                if (value < (INT_MIN + (str[i] - '0'))) {
                    return INT_MIN;
                }
                value -= (str[i] - '0');
            } else {
                if (value > (INT_MAX / 10)) {
                    return INT_MAX;
                }
                value *= 10;
                if (value > (INT_MAX - (str[i] - '0'))) {
                    return INT_MAX;
                }
                value += (str[i] - '0');
            }
        }

        return value;
    }
};

int main()
{
    Solution s;
    // cout << s.myAtoi("123") << endl;
    // cout << s.myAtoi("  123") << endl;
    // cout << s.myAtoi("-123") << endl;
    // cout << s.myAtoi("  -123") << endl;
    // cout << s.myAtoi("123ddf") << endl;
    // cout << s.myAtoi("words and 987") << endl;
    cout << s.myAtoi("2147483648") << endl;

    return 0;
}