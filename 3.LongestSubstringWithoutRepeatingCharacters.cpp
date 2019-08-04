/**
 * @author Mr Dk.
 * @2019.08.04
 */

/*
    Given a string, 
    find the length of the longest substring without repeating characters.

    Example 1:

    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3. 
    Example 2:

    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    Example 3:

    Input: "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3. 
    Note that the answer must be a substring,
    "pwke" is a subsequence and not a substring.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
 * 滑动窗口 + 哈希表
 *      我实在是太菜了为啥一开始就没想到呢 😭
 * 
 * 滑动窗口：
 *      分别用两个变量指示子字符串的首尾
 *      如果尾部字符不重复，则窗口从尾部向后延长
 *      如果尾部字符重复，则窗口从头部缩短
 * 
 * 哈希表：
 *      ASCII 字符表最多 128 个
 *      用一个数组表示对应字符是否出现过
 *      数组下标为 ASCII 编号，数组存储 bool 类型
 */

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::size_t;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Special cases
        if (s.length() <= 1) {
            return s.length();
        }

        size_t longest = 0;
        vector<bool> table(128, false); // hash table

        size_t head = 0;
        size_t tail = 1;
        table[s[head]] = true; // init

        while (tail < s.length()) {
            if (!table[s[tail]]) { // no duplication
                table[s[tail]] = true;
                tail++; // window extends
            } else { // duplication
                table[s[head]] = false;
                head++; // window shortens
            }

            if (tail - head > longest) {
                longest = tail - head; // record length
            }
        }

        return longest;
    }
};

int main() {

    string e1 = "abcabcbb";
    string e2 = "bbbbb";
    string e3 = "pwwkew";
    string e4 = "a";
    string e5 = "abcd";
    string e6 = " ";

    Solution solution;
    cout << solution.lengthOfLongestSubstring(e1) << endl;
    cout << solution.lengthOfLongestSubstring(e2) << endl;
    cout << solution.lengthOfLongestSubstring(e3) << endl;
    cout << solution.lengthOfLongestSubstring(e4) << endl;
    cout << solution.lengthOfLongestSubstring(e5) << endl;
    cout << solution.lengthOfLongestSubstring(e6) << endl;

    return 0;
}
