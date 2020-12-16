/**
 * @author Mr Dk.
 * @version 2020/12/16
 */

/*
    Given a pattern and a string s, find if s follows the same pattern.

    Here follow means a full match, such that there is a bijection between
    a letter in pattern and a non-empty word in s.

    Example 1:
        Input: pattern = "abba", s = "dog cat cat dog"
        Output: true

    Example 2:
        Input: pattern = "abba", s = "dog cat cat fish"
        Output: false

    Example 3:
        Input: pattern = "aaaa", s = "dog cat cat dog"
        Output: false
        
    Example 4:
        Input: pattern = "abba", s = "dog dog dog dog"
        Output: false

    Constraints:
        1 <= pattern.length <= 300
        pattern contains only lower-case English letters.
        1 <= s.length <= 3000
        s contains only lower-case English letters and spaces ' '.
        s does not contain any leading or trailing spaces.
        All the words in s are separated by a single space.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/word-pattern
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    需要使用两个 hash table 分别维护字符和字符串的映射关系，一旦不满足映射
    立刻退出。
    应当提前将字符串 split 为数组，这样可以判断数组长度与 pattern 长度是否
    相等。
 */

#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char_string_map;
        unordered_map<string, char> string_char_map;
        string word(s);
        
        for (size_t i = 0; i < pattern.length(); i++) {
            size_t end = s.find_first_of(' ');
            word.assign(s, 0, end);
            if (word == "") {
                return false;
            }
            if (end == string::npos) {
                s = "";
            } else {
                s.assign(s, end + 1, s.length() - word.length() - 1);
            }

            unordered_map<char, string>::iterator char_string_iter =
                char_string_map.find(pattern[i]);
            unordered_map<string, char>::iterator string_char_iter =
                string_char_map.find(word);

            if (char_string_iter == char_string_map.end() &&
                string_char_iter == string_char_map.end()) {
                char_string_map.insert(std::make_pair(pattern[i], word));
                string_char_map.insert(std::make_pair(word, pattern[i]));
            } else if (char_string_iter != char_string_map.end() &&
                string_char_iter != string_char_map.end()) {

                if (word.compare(char_string_iter->second) ||
                    string_char_iter->second != pattern[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        if (s.length() > 0) {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution s;

    cout << (s.wordPattern("he", "unit") ? "true" : "false") << endl;
    cout << (s.wordPattern("aaa", "aa aa aa aa") ? "true" : "false") << endl;
    cout << (s.wordPattern("abba", "dog cat cat dog") ? "true" : "false") << endl;
    cout << (s.wordPattern("abba", "dog cat cat fish") ? "true" : "false") << endl;
    cout << (s.wordPattern("aaaa", "dog cat cat dog") ? "true" : "false") << endl;
    cout << (s.wordPattern("abba", "dog dog dog dog") ? "true" : "false") << endl;

    return 0;
}