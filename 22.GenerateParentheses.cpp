/**
 * @author Mr DK.
 * @version 2021/03/26
 */

/*
    Given n pairs of parentheses, write a function to generate all
    combinations of well-formed parentheses. 

    Example 1:
        Input: n = 3
        Output: ["((()))","(()())","(())()","()(())","()()()"]

    Example 2:
        Input: n = 1
        Output: ["()"]

    Constraints:
        1 <= n <= 8

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/generate-parentheses
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    深度优先搜素，其中右括号的数量不能多于左括号，当括号数量全部到达上限时，
    保存结果。
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
    int n;

    void dfs(vector<string> &valid_seqs, string &seq, int left, int right) {
        if (left > right && left < n) {
            // both '(' and ')' can be added
            seq.push_back('(');
            dfs(valid_seqs, seq, left + 1, right);
            seq.pop_back();

            seq.push_back(')');
            dfs(valid_seqs, seq, left, right + 1);
            seq.pop_back();
        } else if (left == right && left == n) {
            valid_seqs.push_back(seq);
        } else if (left > right && left == n) {
            // only ')' can be added
            seq.push_back(')');
            dfs(valid_seqs, seq, left, right + 1);
            seq.pop_back();
        } else {
            // left == right && left < n
            // only '(' can be added
            seq.push_back('(');
            dfs(valid_seqs, seq, left + 1, right);
            seq.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;

        vector<string> valid_seqs;
        string sequence("(");
        dfs(valid_seqs, sequence, 1, 0);

        return valid_seqs;
    }
};

int main()
{
    Solution s;
    vector<string> result;

    result = { "((()))", "(()())", "(())()", "()(())", "()()()" };
    assert(result == s.generateParenthesis(3));

    result = { "()" };
    assert(result == s.generateParenthesis(1));

    return 0;
}
