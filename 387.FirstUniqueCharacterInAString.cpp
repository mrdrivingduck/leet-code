/**
 * @author Mr Dk.
 * @version 2020/12/23
 */

/*
    Given a string, find the first non-repeating character in
    it and return its index. If it doesn't exist, return -1.

    Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode"
    return 2. 

    Note: You may assume the string contains only lowercase
    English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    字母桶记录当前出现过的字母。一边向前扫描，一边更新 unique 下标。

    判断 while 条件时，要先把边界条件放前面。
 */

#include <cassert>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int firstUniqChar(string s) {
        int bucket[26] = { 0 };
        size_t unique = 0;

        for (size_t i = 0; i < s.length(); i++) {
            bucket[s[i] - 'a']++;
            while (unique < s.length() && bucket[s[unique] - 'a'] > 1) {
                unique++; // no more unique
            }
        }

        if (unique == s.length()) {
            return -1; // not unique char
        }

        return unique;
    }
};

int main()
{
    Solution s;
    
    assert(-1 == s.firstUniqChar("cc"));
    assert(0 == s.firstUniqChar("leetcode"));
    assert(2 == s.firstUniqChar("loveleetcode"));
    assert(3 == s.firstUniqChar("aaac"));
    assert(-1 == s.firstUniqChar("aaaa"));
    assert(-1 == s.firstUniqChar(""));

    return 0;
}
