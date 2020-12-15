/**
 * @author Mr Dk.
 * @version 2020/12/15
 */

/*
    Given a non-negative integer N, find the largest number that is less
    than or equal to N with monotone increasing digits.

    (Recall that an integer has monotone increasing digits if and only if
    each pair of adjacent digits x and y satisfy x <= y.)

    Example 1:
        Input: N = 10
        Output: 9
    
    Example 2:
        Input: N = 1234
        Output: 1234

    Example 3:
        Input: N = 332
        Output: 299

    Note: N is an integer in the range [0, 10^9].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/monotone-increasing-digits
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    找到第一个递减的位，将之后所有的数位都设置为 '9'，并将前一位减 1；如果前一位
    减 1 后不符合单调递增，那么将这一位赋值为 '9'，将再前一位减 1。
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string digits = std::to_string(N);

        for (size_t i = 0; i < digits.length(); i++) {
            if (digits[i] < digits[i - 1]) {
                for (size_t j = i; j < digits.length(); j++) {
                    digits[j] = '9';
                }
                digits[--i]--;
                while (i > 0 && digits[i] < digits[i - 1]) {
                    digits[i - 1]--;
                    digits[i] = '9';
                    i--;
                }

                return std::stoi(digits);
            }
        }

        return N;
    }
};

int main()
{
    Solution s;

    cout << s.monotoneIncreasingDigits(10) << endl;
    cout << s.monotoneIncreasingDigits(1234) << endl;
    cout << s.monotoneIncreasingDigits(33323) << endl;
    cout << s.monotoneIncreasingDigits(1234543) << endl;

    return 0;
}
