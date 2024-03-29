/**
 * @author Mr Dk.
 * @version 2021/01/16
 */

/*
    请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

    示例 1:
        输入: "abcabcbb"
        输出: 3 
        解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

    示例 2:
        输入: "bbbbb"
        输出: 1
        解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

    示例 3:
        输入: "pwwkew"
        输出: 3
        解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
             请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

    提示：
        s.length <= 40000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    用一个 hash table (或者说桶) 维护字符串中的不重复子串。当遇到重复字符时，
    不重复子串从头部缩短；遇到不重复字符时，不重复子串从尾部延长。
*/

#include <cassert>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[128] = { 0 };
        size_t len = 0;
        size_t head = 0;
        size_t tail = 0;

        while (tail < s.length()) {
            if (map[s[tail] - 0]) {
                map[s[head] - 0]--;
                head++;
            } else {
                map[s[tail] - 0]++;
                tail++;
                if (len < tail - head) {
                    len = tail - head;
                }
            }
        }

        return len;
    }
};

int main()
{
    Solution s;
    
    assert(3 == s.lengthOfLongestSubstring("abcabcbb"));
    assert(1 == s.lengthOfLongestSubstring("bbbbb"));
    assert(3 == s.lengthOfLongestSubstring("pwwkew"));

    return 0;
}
