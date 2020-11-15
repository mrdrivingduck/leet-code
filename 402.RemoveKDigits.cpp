/**
 * @author Mr Dk.
 * @version 2020.11.15
 */

/*
    Given a non-negative integer num represented as a string, remove k
    digits from the number so that the new number is the smallest possible.

    Note:
        The length of num is less than 10002 and will be ≥ k.
        The given num does not contain any leading zero.

    Example 1:
        Input: num = "1432219", k = 3
        Output: "1219"
        Explanation: Remove the three digits 4, 3, and 2 to form the new number 
                        219 which is the smallest.

    Example 2:
        Input: num = "10200", k = 1
        Output: "200"
        Explanation: Remove the leading 1 and the number is 200. Note that the
                        output must not contain leading zeroes.

    Example 3:
        Input: num = "10", k = 2
        Output: "0"
        Explanation: Remove all the digits from the number and it is left with
                        nothing which is 0.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/remove-k-digits
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    单调递增栈：保持一个栈内的元素是单调递增的。如果栈内元素无法满足要求，则 pop 直到符合
    要求为止。用一个栈结构来维护一个指定长度的单调递增子序列。为什么是单调递增呢，因为相同
    长度的序列，前面的数越小，那么这个序列对应的数字就越小。但是，由于题目对子序列的长度有
    限制，因此也不能无限制地 pop。当 k 已经用尽后，就不能再 pop 了；当序列遍历完毕后 k
    还没有用完，那么就从栈顶开始 pop，直到把 k 用尽。如果最终的子序列为空，那么返回数字 0
    的字符串。

    注意不能让前导 0 进入单调递增栈。
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string removeKdigits(string num, int k) {
        size_t i = 0;
        string s;
        while (i < num.size()) {
            while (!num.empty() && s.back() > num[i] && k > 0) {
                s.pop_back();
                k--;
            }
            if (!s.empty() || num[i] != '0') {
                s.push_back(num[i]);
            }
            
            i++;
        }
        
        while (k > 0 && !s.empty()) {
            s.pop_back();
            k--;
        }
        if (s.empty()) {
            s.push_back('0');
        }

        return s;
    }
};

int main() {
    Solution s;
    cout << s.removeKdigits("1432219", 3) << endl;
    cout << s.removeKdigits("10200", 1) << endl;
    cout << s.removeKdigits("10", 2) << endl;
    cout << s.removeKdigits("10", 1) << endl;
    cout << s.removeKdigits("112", 1) << endl;
    cout << s.removeKdigits("1234567890", 9) << endl;

    return 0;
}
