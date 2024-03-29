/**
 * @author Mr Dk.
 * @version 2020/08/31
 */

/*
    Roman numerals are represented by seven different symbols:
    I, V, X, L, C, D and M.

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000

    For example, two is written as II in Roman numeral, just two one's added
    together. Twelve is written as, XII, which is simply X + II. The number
    twenty seven is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right.
    However, the numeral for four is not IIII. Instead, the number four is
    written as IV. Because the one is before the five we subtract it making
    four. The same principle applies to the number nine, which is written as
    IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

    Example 1:

    Input: 3
    Output: "III"
    Example 2:

    Input: 4
    Output: "IV"
    Example 3:

    Input: 9
    Output: "IX"
    Example 4:

    Input: 58
    Output: "LVIII"
    Explanation: L = 50, V = 5, III = 3.
    Example 5:

    Input: 1994
    Output: "MCMXCIV"
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/integer-to-roman
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
private:
    int radix[8] = { 5000, 1000, 500, 100, 50, 10, 5, 1 };
    char radix_chr[8] = { '@', 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
public:
    string intToRoman(int num) {
        string str("");

        for (int i = 0; i < 8; i += 2) {

            int mod = num / radix[i + 1]; // 取最高位数字
            num -= mod * radix[i + 1]; // 去除掉最高位数字
            
            // 本轮数字为 0，不对应任何罗马字母
            if (mod == 0) {
                continue;
            }

            // 特殊处理 4 和 9
            if (mod == 4) {
                str += radix_chr[i + 1];
                str += radix_chr[i];
            } else if (mod == 9) {
                str += radix_chr[i + 1];
                str += radix_chr[i - 1];
            } else {
                // 普通情况
                
                // 特殊处理大于 5 的最高位数字
                if (mod >= 5) {
                    str += radix_chr[i];
                    mod -= 5;
                }
                
                // 剩余的个位数字
                for (int j = 0; j < mod; j++) {
                    str += radix_chr[i + 1];
                }
            }
        }

        return str;
    }
};

int main()
{
    Solution solution;

    cout << solution.intToRoman(3) << endl;
    cout << solution.intToRoman(4) << endl;
    cout << solution.intToRoman(9) << endl;
    cout << solution.intToRoman(58) << endl;
    cout << solution.intToRoman(1994) << endl;

    return 0;
}