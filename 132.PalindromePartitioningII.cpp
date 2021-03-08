/**
 * @author Mr Dk.
 * @version 2021/03/08
 */

/*
    Given a string s, partition s such that every substring of the
    partition is a palindrome.

    Return the minimum cuts needed for a palindrome partitioning of s. 

    Example 1:
        Input: s = "aab"
        Output: 1
        Explanation:
            The palindrome partitioning ["aa","b"] could be produced
            using 1 cut.

    Example 2:
        Input: s = "a"
        Output: 0

    Example 3:
        Input: s = "ab"
        Output: 1

    Constraints:
        1 <= s.length <= 2000
        s consists of lower-case English letters only.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    再用深度优先搜素将超时。

    第一次动态规划：
    先将每个子串是否为回文串登记在数组内，以便之后的 O(1) 查询。

    第二次动态规划：
    依次计算每个前缀串的最小分割次数。对于每个前缀串，如：cbbbc，
    依次计算 [cbbb, c] [cbb, bc] [cb, bbc] [c, bbbc], [, cbbbc] 中
    后一个子串是否为回文串，如果是，则最小分割次数为前一个子串的最小分割次数 + 1。
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
    int minCut(string s) {
        vector<vector<int>> is_palindrome(s.length(), vector<int>(s.length(), 1));
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j < (int) s.length(); j++) {
                if (i >= j) {
                    is_palindrome[i][j] = 1;
                } else if (s[i] == s[j]) {
                    is_palindrome[i][j] = is_palindrome[i + 1][j - 1];
                } else {
                    is_palindrome[i][j] = 0;
                }
            }
        }

        vector<int> prefix_palindrome(s.length(), INT32_MAX);
        prefix_palindrome[0] = 0;
        for (size_t i = 1; i < s.length(); i++) {
            if (is_palindrome[0][i]) {
                prefix_palindrome[i] = 0;
                continue;
            }
            for (int j = i - 1; j >= 0; j--) {
                if (is_palindrome[j + 1][i]) {
                    prefix_palindrome[i] = std::min(prefix_palindrome[j] + 1, prefix_palindrome[i]);
                }
            }
        }

        return prefix_palindrome[prefix_palindrome.size() - 1];
    }
};

int main()
{
    Solution s;

    assert(1 == s.minCut("cbbbcc"));

    assert(2 == s.minCut("leet"));
    
    assert(1 == s.minCut("aab"));

    assert(0 == s.minCut("a"));

    assert(1 == s.minCut("ab"));

    return 0;
}
