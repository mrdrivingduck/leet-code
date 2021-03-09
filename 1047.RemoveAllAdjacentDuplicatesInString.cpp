/**
 * @author Mr Dk.
 * @version 2021/03/09
 */

/*
    Given a string S of lowercase letters, a duplicate removal consists
    of choosing two adjacent and equal letters, and removing them.

    We repeatedly make duplicate removals on S until we no longer can.

    Return the final string after all such duplicate removals have been
    made.  It is guaranteed the answer is unique. 

    Example 1:
        Input: "abbaca"
        Output: "ca"
        Explanation: 
            For example, in "abbaca" we could remove "bb" since the letters
            are adjacent and equal, and this is the only possible move.
            The result of this move is that the string is "aaca", of which
            only "aa" is possible, so the final string is "ca".

    Note:
        1 <= S.length <= 20000
        S consists only of English lowercase letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    维护一个栈，同时遍历字符串。如果字符和当前栈顶相同，则弹栈；否则字符入栈。
    最终栈内剩余的字符就是结果。
 */

#include <cassert>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string removeDuplicates(string S) {
        string result;

        for (size_t i = 0; i < S.length(); i++) {
            if (!result.empty() && result[result.length() - 1] == S[i]) {
                result.pop_back();
            } else {
                result.push_back(S[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    
    assert("ca" == s.removeDuplicates("abbaca"));

    return 0;
}
