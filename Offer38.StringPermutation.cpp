/**
 * @author Mr Dk.
 * @version 2020/11/20
 */

/*
    输入一个字符串，打印出该字符串中字符的所有排列。
    你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

    示例:
        输入：s = "abc"
        输出：["abc","acb","bac","bca","cab","cba"]
     
    限制：
        1 <= s 的长度 <= 8

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    暴力解法会超时，问题主要出在，遍历了所有的情况，然后再过滤了重复情况，太浪费
    时间。采用深度优先搜索的方式解决，能够对每个层次中相同的字母进行剪枝，从而
    避免产生重复的排列序列。
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::string;

class Solution {
public:

    vector<string> permutation(string s) {
        vector<bool> use(s.length(), false);
        vector<string> result;
        string worker;

        dfs(s, worker, result, use);

        return result;
    }

    void dfs(string &s, string &partial_result, vector<string> &result, vector<bool> &use) {
        string used_chars;
        for (size_t i = 0; i < use.size(); i++) {
            if (!use[i] && used_chars.find(s[i]) == string::npos) {
                use[i] = true;
                used_chars.push_back(s[i]);
                partial_result.push_back(s[i]);
                if (partial_result.length() == s.length()) {
                    string copy(partial_result);
                    result.push_back(copy);
                } else {
                    dfs(s, partial_result, result, use);
                }
                partial_result.pop_back();
                use[i] = false;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<string> result = s.permutation("Hell");
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    cout << result.size() << endl;

    result = s.permutation("a");
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    cout << result.size() << endl;

    result = s.permutation("kzfxxx");
    cout << result.size() << endl;
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    cout << result.size() << endl;

    return 0;
}