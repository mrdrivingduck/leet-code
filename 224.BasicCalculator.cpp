/**
 * @author Mr Dk.
 * @version 2021/03/10
 */

/*
    Given a string s representing an expression, implement a basic
    calculator to evaluate it. 

    Example 1:
        Input: s = "1 + 1"
        Output: 2

    Example 2:
        Input: s = " 2-1 + 2 "
        Output: 3

    Example 3:
        Input: s = "(1+(4+5+2)-3)+(6+8)"
        Output: 23

    Constraints:
        1 <= s.length <= 3 * 105
        s consists of digits, '+', '-', '(', ')', and ' '.
        s represents a valid expression.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/basic-calculator
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    
 */

#include <cassert>

#include <iostream>
#include <string>
#include <stack>
using std::string;
using std::stack;
using std::cout;
using std::endl;

class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> op_nums;

        size_t i = 0;
        char top_op;
        while (i < s.length()) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '(') {
                op.push('(');
                i++;
            } else if (s[i] == '+' || s[i] == '-') {
                while (!op.empty() && ((top_op = op.top()) == '+' || top_op == '-')) {
                    op.pop();
                    int op2 = op_nums.top();
                    op_nums.pop();
                    int op1 = 0;
                    if (!op_nums.empty()) {
                        op1 = op_nums.top();
                        op_nums.pop();
                    }

                    if (top_op == '+') {
                        op_nums.push(op1 + op2);
                    } else if (top_op == '-') {
                        op_nums.push(op1 - op2);
                    }
                }
                op.push(s[i]);
                i++;
            } else if (s[i] == ')') {
                while (!op.empty() && (top_op = op.top()) != '(') {
                    op.pop();
                    int op2 = op_nums.top();
                    op_nums.pop();
                    int op1 = 0;
                    if (!op_nums.empty()) {
                        op1 = op_nums.top();
                        op_nums.pop();
                    }

                    if (top_op == '+') {
                        op_nums.push(op1 + op2);
                    } else if (top_op == '-') {
                        op_nums.push(op1 - op2);
                    }
                }
                if (!op.empty()) {
                    op.pop();
                }
                i++;
            } else {
                int num = s[i] - '0';
                i++;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num *= 10;
                    num += s[i] - '0';
                    i++;
                }
                op_nums.push(num);
            }
        }

        while (!op.empty() && ((top_op = op.top()) == '+' || top_op == '-')) {
            op.pop();
            int op2 = op_nums.top();
            op_nums.pop();
            int op1 = 0;
            if (!op_nums.empty()) {
                op1 = op_nums.top();
                op_nums.pop();
            }

            if (top_op == '+') {
                op_nums.push(op1 + op2);
            } else if (top_op == '-') {
                op_nums.push(op1 - op2);
            }
        }

        return op_nums.top();
    }
};

int main()
{
    Solution s;
    
    // assert(2 == s.calculate("1 + 1"));

    // assert(3 == s.calculate(" 2-1 + 2"));

    // assert(23 == s.calculate("(1+(4+5+2)-3)+(6+8)"));

    // assert(-1 == s.calculate("-2+ 1"));

    assert(-12 == s.calculate("- (3 + (4 + 5))"));

    return 0;
}
