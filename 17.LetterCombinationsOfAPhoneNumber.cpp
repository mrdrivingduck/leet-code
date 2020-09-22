/**
 * @author Mr Dk.
 * @version 2020/09/22
 */

/*
    Given a string containing digits from 2-9 inclusive, return all possible
    letter combinations that the number could represent.

    A mapping of digit to letters (just like on the telephone buttons) is given
    below. Note that 1 does not map to any letters.

    Example:

    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    Note:

    Although the above answer is in lexicographical order, your answer could be
    in any order you want.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    递归构造字符串。
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
private:
    vector<string> table = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> all_strings;

        if (digits.length() < 1) {
            return all_strings;
        }

        string init;
        combine(all_strings, init, digits, 0);

        return all_strings;
    };

    void combine(vector<string> &all_strings, string build, string &digits, unsigned int index) {
        char ch = digits.at(index);
        string candidates = table[ch - '0'];
        for (unsigned int i = 0; i < candidates.length(); i++) {
            string next(build); // Copy 一个副本用于递归
            next.push_back(candidates[i]); // 放入下一个字符

            if (index + 1 == digits.length()) {
                // 递归出口
                all_strings.push_back(next);
            } else {
                // 继续向下层递归
                combine(all_strings, next, digits, index + 1);
            }
        }
    };
};

int main()
{
    Solution s;
    vector<string> all_strings = s.letterCombinations("23");
    for (unsigned int i = 0; i < all_strings.size(); i++) {
        cout << all_strings[i] << endl;
    }

    return 0;
}