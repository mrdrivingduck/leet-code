/**
 * @author Mr Dk.
 * @version 2020/12/08
 */

/*
    Given a string S of digits, such as S = "123456579", we can split it
    into a Fibonacci-like sequence [123, 456, 579].

    Formally, a Fibonacci-like sequence is a list F of non-negative integers
    such that:

        0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed
        integer type);
        F.length >= 3;
        and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.

    Also, note that when splitting the string into pieces, each piece must
    not have extra leading zeroes, except if the piece is the number 0 itself.

    Return any Fibonacci-like sequence split from S, or return [] if it cannot
    be done.

    Example 1:
        Input: "123456579"
        Output: [123,456,579]

    Example 2:
        Input: "11235813"
        Output: [1,1,2,3,5,8,13]

    Example 3:
        Input: "112358130"
        Output: []
        Explanation: The task is impossible.

    Example 4:
        Input: "0123"
        Output: []
        Explanation: Leading zeroes are not allowed, so "01", "2", "3" is
                        not valid.

    Example 5:
        Input: "1101111"
        Output: [110, 1, 111]
        Explanation: The output [11, 0, 11, 11] would also be accepted.

    Note:
        1 <= S.length <= 200
        S contains only digits.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    不断切分出前缀相同的子字符串："a" "ab" "abc"，并判断是否为已有序列中最后两个数字的和，
    如果是，则将该数加入序列，递归剩余的子字符串；如果该前缀的所有子字符串都无法满足斐波那契
    数列的要求，则回溯。

    注意加法中整数溢出的情况。尽可能先用字符串比较；转换成 int 型后，通过做减法而不是加法
    来判断是否符合斐波那契数列的要求。
 */

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

string MAX_STR("2147483647"); // INT_MAX

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> seq;
        split(seq, S, 0);
        return seq;
    }

    bool split(vector<int> &seq, string &str, size_t start) {
        for (size_t i = start; i < str.length(); i++) {

            string s(str, start, i - start + 1);

            // non-zero number cannot start with '0'
            if (s.length() > 1 && s[0] == '0') {
                return false;
            }

            // signed interger overflow
            if (s.length() > MAX_STR.length() ||
                (s.length() == MAX_STR.length() && s > MAX_STR)) {
                return false;
            }

            int number = std::stoi(s);
            if (seq.size() < 2) {
                // not yet Fibonacci-like sequence
                // sequence length is not enough
                seq.push_back(number);
                if (i + 1 < str.length() && split(seq, str, i + 1)) {
                    return true;
                }
                seq.pop_back();
            } else {
                if (seq[seq.size() - 2] == number - seq[seq.size() - 1]) {
                    seq.push_back(number);
                    // the last character OR substring is OK
                    if (i + 1 == str.length() || split(seq, str, i + 1)) {
                        return true;
                    }
                    seq.pop_back();
                }
            }
        }

        // all substring start with [start] cannot be Fibonacci-like sequence
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> seq;

    seq = s.splitIntoFibonacci("214748364721474836422147483641");
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    seq = s.splitIntoFibonacci("123456579");
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    seq = s.splitIntoFibonacci("11235813");
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    seq = s.splitIntoFibonacci("112358130");
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    seq = s.splitIntoFibonacci("0123");
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    seq = s.splitIntoFibonacci("1101111");
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    return 0;
}
