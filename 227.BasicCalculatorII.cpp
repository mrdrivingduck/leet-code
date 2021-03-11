/**
 * @author Mr Dk.
 * @version 2021/03/11
 */

/*
    Given a string s which represents an expression, evaluate this
    expression and return its value. 

    The integer division should truncate toward zero. 

    Example 1:
        Input: s = "3+2*2"
        Output: 7

    Example 2:
        Input: s = " 3/2 "
        Output: 1

    Example 3:
        Input: s = " 3+5 / 2 "
        Output: 5

    Constraints:
        1 <= s.length <= 3 * 105
        s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
        s represents a valid expression.
        All the integers in the expression are non-negative integers in the range [0, 231 - 1].
        The answer is guaranteed to fit in a 32-bit integer.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/basic-calculator-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    维护一个操作数栈和操作符栈。
    当遇到一个低优先级的运算符时，尽可能将栈顶的高优先级的运算符运算完毕；
    当遇到一个相同优先级的运算符时，尽可能将栈顶的相同等级的运算符运算完毕。

    优先级：乘法 == 除法 > 加号 == 减号。
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
            } else if (s[i] == '*' || s[i] == '/') {
                while (!op.empty() && ((top_op = op.top()) == '*' || top_op == '/')) {
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
                    } else if (top_op == '*') {
                        op_nums.push(op1 * op2);
                    } else if (top_op == '/') {
                        op_nums.push(op1 / op2);
                    }
                }
                op.push(s[i]);
                i++;
            } else if (s[i] == '+' || s[i] == '-') {
                while (!op.empty()) {
                    top_op = op.top();
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
                    } else if (top_op == '*') {
                        op_nums.push(op1 * op2);
                    } else if (top_op == '/') {
                        op_nums.push(op1 / op2);
                    }
                }
                op.push(s[i]);
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

        while (!op.empty()) {
            top_op = op.top();
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
            } else if (top_op == '*') {
                op_nums.push(op1 * op2);
            } else if (top_op == '/') {
                op_nums.push(op1 / op2);
            }
        }

        return op_nums.top();
    }
};

int main()
{
    Solution s;

    assert(8 == s.calculate("14/3*2"));
    
    assert(7 == s.calculate("3+2*2"));

    assert(1 == s.calculate(" 3/2"));

    assert(5 == s.calculate(" 3+5 / 2 "));

    return 0;
}
