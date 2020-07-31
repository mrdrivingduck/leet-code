/**
 * @author Mr Dk.
 * @version 2020/07/31
 */

/*
    The string "PAYPALISHIRING" is written in a zigzag pattern
    on a given number of rows like this: (you may want to display
    this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"

    Write the code that will take a string and make this conversion
    given a number of rows:

    string convert(string s, int numRows);
    Example 1:

    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"
    Example 2:

    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:

    P     I    N
    A   L S  I G
    Y A   H R
    P     I

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zigzag-conversion
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    根据规律，似乎可以算出一个递推公式：

    假设行号为 l，取值范围为 [0, numRow-1]，
    那么每一行的字母在字符串中的下标为 x = l - 1
    x (+ 2 * (numRow - 1 - x)) (+ 2 * (x - 0))
*/

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        string res(s);
        int res_idx = 0;

        for (int line = 0; line < numRows; line++) {
            unsigned int idx = line;
            int next_off_down = 0;
            int next_off_up = 0;
            while (idx < s.length()) {
                if (idx == (unsigned int) line) {
                    // 第一次
                    res[res_idx] = s[idx];
                    res_idx++;
                }
                
                // ZIGZAG 向下行走
                next_off_down = 2 * (numRows - 1 - line);
                idx += next_off_down;
                if (idx >= s.length()) {
                    break;
                }
                if (next_off_down) {
                    // 最底下一行不需要向下走
                    res[res_idx] = s[idx];
                    res_idx++;
                }

                // ZIGZAG 向上行走
                next_off_up = 2 * line;
                idx += next_off_up;
                if (idx >= s.length()) {
                    break;
                }
                if (next_off_up) {
                    // 最上面一行不需要向上走
                    res[res_idx] = s[idx];
                    res_idx++;
                }

                // 向下或向上都不能走，则退出防止死循环
                // Test case: "A" 1
                if (!next_off_down && !next_off_up) {
                    break;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    string str("PAYPALISHIRING");
    cout << s.convert(str, 3) << endl;
    return 0;
}