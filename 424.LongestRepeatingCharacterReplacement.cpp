/**
 * @author Mr Dk.
 * @version 2021/02/02
 */

/*
    Given a string s that consists of only uppercase English letters,
    you can perform at most k operations on that string.

    In one operation, you can choose any character of the string and
    change it to any other uppercase English character.

    Find the length of the longest sub-string containing all repeating
    letters you can get after performing the above operations.

    Note:
    Both the string's length and k will not exceed 104.

    Example 1:
        Input:
            s = "ABAB", k = 2
        Output:
            4
        Explanation:
            Replace the two 'A's with two 'B's or vice versa.

    Example 2:
        Input:
            s = "AABABBA", k = 1
        Output:
            4
        Explanation:
            Replace the one 'A' in the middle with 'B' and form "AABBBBA".
            The substring "BBBB" has the longest repeating letters, which is 4.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    通过左右指针维护一个滑动窗口，并记录窗口内重复字母出现次数的最大值。如果窗口
    长度已经超出了重复字母出现次数的最大值 + 允许修改的字母个数，那么这个滑动窗口
    就违反要求了，将左指针向右移动缩小窗口长度。
 */

#include <cassert>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int characterReplacement(string s, int k) {
        size_t left = 0;
        size_t right = 0;
        int bucket[26] = { 0 };
        int max_char = 0;
        
        while (right < s.length()) {
            bucket[s[right] - 'A']++;
            if (bucket[s[right] - 'A'] > max_char) {
                max_char = bucket[s[right] - 'A'];
            }

            // length of window: right - left + 1
            // limit exceeded
            if (((int) (right - left + 1)) > max_char + k) {
                bucket[s[left] - 'A']--;
                left++;
            }

            right++;
        }

        return right - left;
    }
};

int main()
{
    Solution s;
    
    assert(4 == s.characterReplacement("ABAB", 2));
    assert(4 == s.characterReplacement("AABABBA", 1));

    return 0;
}
