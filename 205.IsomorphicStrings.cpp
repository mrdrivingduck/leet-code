/**
 * @author Mr Dk.
 * @version 2020/12/27
 */

/*
    Given two strings s and t, determine if they are isomorphic.

    Two strings are isomorphic if the characters in s can be replaced to get t.

    All occurrences of a character must be replaced with another character
    while preserving the order of characters. No two characters may map to
    the same character but a character may map to itself.

    Example 1:
        Input: s = "egg", t = "add"
        Output: true

    Example 2:
        Input: s = "foo", t = "bar"
        Output: false

    Example 3:
        Input: s = "paper", t = "title"
        Output: true

    Note:
        You may assume both s and t have the same length.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/isomorphic-strings
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    用两个 hash 表维护双射关系 (用数组也行，如果预先知道字符范围)，一旦
    不符合双射关系就立刻退出。
 */

#include <cassert>

#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;
        unordered_map<char, char>::iterator s_to_t_iter;
        unordered_map<char, char>::iterator t_to_s_iter;

        for (size_t i = 0; i < s.length(); i++) {
            s_to_t_iter = s_to_t.find(s[i]);
            t_to_s_iter = t_to_s.find(t[i]);

            if (s_to_t_iter == s_to_t.end() && t_to_s_iter == t_to_s.end()) {
                s_to_t.insert(std::make_pair(s[i], t[i]));
                t_to_s.insert(std::make_pair(t[i], s[i]));
            } else if (s_to_t_iter != s_to_t.end() && t_to_s_iter != t_to_s.end()) {
                if (s_to_t_iter->second != t[i] || t_to_s_iter->second != s[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    assert(true == s.isIsomorphic("egg", "add"));
    assert(false == s.isIsomorphic("foo", "bar"));
    assert(true == s.isIsomorphic("paper", "title"));

    return 0;
}