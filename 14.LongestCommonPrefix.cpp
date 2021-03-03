/**
 * @author Mr Dk.
 * @version 2021/03/03
 */

/*
    Write a function to find the longest common prefix string amongst
    an array of strings.

    If there is no common prefix, return an empty string "". 

    Example 1:
        Input: strs = ["flower","flow","flight"]
        Output: "fl"

    Example 2:
        Input: strs = ["dog","racecar","car"]
        Output: ""

    Explanation: There is no common prefix among the input strings.

    Constraints:
        0 <= strs.length <= 200
        0 <= strs[i].length <= 200
        strs[i] consists of only lower-case English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-common-prefix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    选择一个字符串作为基准，依次与其它字符串比较前缀即可。
*/

#include <cassert>

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        if (!strs.size()) {
            return prefix;
        }

        for (size_t i = 0; i < strs[0].size(); i++) {
            bool add = true;
            for (size_t j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    add = false;
                    break;
                }
            }
            if (add) {
                prefix.push_back(strs[0][i]);
            } else {
                break;
            }
        }

        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> strs;

    strs = { "flower","flow","flight" };
    assert("fl" == s.longestCommonPrefix(strs));

    strs = { "dog","racecar","car" };
    assert("" == s.longestCommonPrefix(strs));

    return 0;
}