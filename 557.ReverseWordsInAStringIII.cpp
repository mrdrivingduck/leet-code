/**
 * @author Mr Dk.
 * @version 2021/03/11
 */

/*
    Given a string s, reverse the order of characters in each word within a
    sentence while still preserving whitespace and initial word order.

    Example 1:
        Input: s = "Let's take LeetCode contest"
        Output: "s'teL ekat edoCteeL tsetnoc"

    Example 2:
        Input: s = "God Ding"
        Output: "doG gniD"

    Constraints:
        1 <= s.length <= 5 * 104
        s contains printable ASCII characters.
        s does not contain any leading or trailing spaces.
        There is at least one word in s.
        All the words in s are separated by a single space.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    切分出每个字符串并反转。
 */

#include <cassert>

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using std::string;
using std::stringstream;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        result.reserve(s.length());
        stringstream ss(s);

        string word;
        while (getline(ss, word, ' ')) {
            std::reverse(word.begin(), word.end());
            result.insert(result.end(), word.begin(), word.end());
            result.push_back(' ');
        }

        result.pop_back();
        return result;
    }
};

int main()
{
    Solution s;

    assert("s'teL ekat edoCteeL tsetnoc" == s.reverseWords("Let's take LeetCode contest"));

    assert("doG gniD" == s.reverseWords("God Ding"));

    return 0;
}
