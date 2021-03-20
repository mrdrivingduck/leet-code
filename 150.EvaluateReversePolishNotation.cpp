/**
 * @author Mr Dk.
 * @version 2021/03/20
 */

/*
    Evaluate the value of an arithmetic expression in Reverse Polish
    Notation.

    Valid operators are +, -, *, and /. Each operand may be an integer
    or another expression.

    Note that division between two integers should truncate toward zero.

    It is guaranteed that the given RPN expression is always valid. That
    means the expression would always evaluate to a result, and there
    will not be any division by zero operation.

    Example 1:
        Input: tokens = ["2","1","+","3","*"]
        Output: 9
        Explanation: ((2 + 1) * 3) = 9

    Example 2:
        Input: tokens = ["4","13","5","/","+"]
        Output: 6
        Explanation: (4 + (13 / 5)) = 6

    Example 3:
        Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
        Output: 22
        Explanation:
            ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
            = ((10 * (6 / (12 * -11))) + 17) + 5
            = ((10 * (6 / -132)) + 17) + 5
            = ((10 * 0) + 17) + 5
            = (0 + 17) + 5
            = 17 + 5
            = 22

    Constraints:
        1 <= tokens.length <= 104
        tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    逆波兰式又称后缀表达式。维护一个栈，从左到右遍历表达式：
        1. 如果是一个操作数，则入栈
        2. 如果时一个运算符，则从栈顶先后弹出右操作数和左操作数，运算后，将运算结果压回栈中
    最终，栈内剩下的那个数就是表达式的运算结果。
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
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int left;
        int right;

        for (size_t i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                right = stack[stack.size() - 1];
                stack.pop_back();
                left = stack[stack.size() - 1];
                stack.pop_back();

                left += right;
                stack.push_back(left);
            } else if (tokens[i] == "-") {
                right = stack[stack.size() - 1];
                stack.pop_back();
                left = stack[stack.size() - 1];
                stack.pop_back();

                left -= right;
                stack.push_back(left);
            } else if (tokens[i] == "*") {
                right = stack[stack.size() - 1];
                stack.pop_back();
                left = stack[stack.size() - 1];
                stack.pop_back();

                left *= right;
                stack.push_back(left);
            } else if (tokens[i] == "/") {
                right = stack[stack.size() - 1];
                stack.pop_back();
                left = stack[stack.size() - 1];
                stack.pop_back();

                left /= right;
                stack.push_back(left);
            } else {
                left = std::stoi(tokens[i]);
                stack.push_back(left);
            }
        }

        return stack[stack.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<string> tokens;

    tokens = { "2","1","+","3","*" };
    assert(9 == s.evalRPN(tokens));

    tokens = { "4","13","5","/","+" };
    assert(6 == s.evalRPN(tokens));

    tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    assert(22 == s.evalRPN(tokens));

    return 0;
}
