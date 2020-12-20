/**
 * @author Mr Dk.
 * @version 2020/12/20
 */

/*
    Given a string s, remove duplicate letters so that every letter appears
    once and only once. You must make sure your result is the smallest in
    lexicographical order among all possible results.

    Note: This question is the same as 1081:
    https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

    Example 1:
        Input: s = "bcabc"
        Output: "abc"

    Example 2:
        Input: s = "cbacdcbc"
        Output: "acdb"

    Constraints:
        1 <= s.length <= 10^4
        s consists of lowercase English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/remove-duplicate-letters
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    要得到一个字典序最小的序列，想到肯定需要使用单调栈，使得靠前的字母尽可能小。
    首先，栈中已经有了的字符，尽可以忽略掉。对于一个栈中没有的字符，如果遇到一
    个比当前栈顶更大的字符，那么就直接入栈；如果遇到一个比当前栈顶更小的字符，
    那么是有机会使得序列变小的，具体取决于当前栈顶元素是否在之后还会出现：

        1. 如果当前栈顶元素之后还会出现，那么我们尽可以把当前栈顶的元素丢弃，
        让它之后再入栈好了；
        2. 如果当前栈顶元素之后不再会出现，那么它必须被留在栈中，不然最终的栈
        中就肯定没有这个字母了。

    由此，关键点在于判断两件事情，分别由两个 hash table (或长度为 26 的字母桶)
    实现：
        1. 当前栈中是否存在某个字母
        2. 当前序列位置之后是否还会出现某个字母
 */

#include <cassert>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int bucket[26] = { 0 }; // char bucket
        for (size_t i = 0; i < s.length(); i++) {
            bucket[s[i] - 'a']++;
        }

        string stack;
        bool exist[26] = { false }; // char existence in stack
        
        for (size_t i = 0; i < s.length(); i++) {
            if (exist[s[i] - 'a']) { // char already exist in stack
                bucket[s[i] - 'a']--; // consume the char
                continue;
            }

            // pop stack until can be pushed
            while (!stack.empty()) {
                if (s[i] < stack[stack.size() - 1] &&
                        bucket[stack[stack.size() - 1] - 'a'] > 0) {
                    // char < stack top && stack top will show up later
                    // pop stack top
                    exist[stack[stack.size() - 1] - 'a'] = false;
                    stack.pop_back();
                } else {
                    // stack push position
                    break;
                }
            }

            // push into stack
            stack.push_back(s[i]);
            exist[s[i] - 'a'] = true;
            bucket[s[i] - 'a']--;
        }

        return stack;
    }
};

int main()
{
    Solution s;
    string result;

    assert("bac" == s.removeDuplicateLetters("bbcaac"));
    assert("abc" == s.removeDuplicateLetters("bcabc"));
    assert("acdb" == s.removeDuplicateLetters("cbacdcbc"));
    
    return 0;
}
