/**
 * @author Mr Dk.
 * @version 2021/04/01
 */

/*
    Normally, the factorial of a positive integer n is the product of all
    positive integers less than or equal to n.  For example, factorial(10)
    = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.

    We instead make a clumsy factorial: using the integers in decreasing
    order, we swap out the multiply operations for a fixed rotation of
    operations: multiply (*), divide (/), add (+) and subtract (-) in this
    order.

    For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  
    However, these operations are still applied using the usual order of
    operations of arithmetic: we do all multiplication and division steps
    before any addition or subtraction steps, and multiplication and
    division steps are processed left to right.

    Additionally, the division that we use is floor division such that
    10 * 9 / 8 equals 11.  This guarantees the result is an integer.

    Implement the clumsy function as defined above: given an integer N,
    it returns the clumsy factorial of N. 

    Example 1:
        Input: 4
        Output: 7
        Explanation: 7 = 4 * 3 / 2 + 1

    Example 2:
        Input: 10
        Output: 12
        Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1

    Note:
        1 <= N <= 10000
        -2^31 <= answer <= 2^31 - 1
            (The answer is guaranteed to fit within a 32-bit integer.)

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/clumsy-factorial
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    模拟栈解法即可，效率略低。
 */

#include <cassert>

#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

class Solution {
public:
    int clumsy(int N) {
        char op = '*';
        stack<int> op_nums;
        stack<char> ops;
        op_nums.push(N--);

        while (op_nums.size() > 1 || N) {
            if (op == '*') {
                while (op_nums.size() > 1 && (ops.top() == '*' || ops.top() == '/')) {
                    char _op = ops.top();
                    ops.pop();
                    int op2 = op_nums.top();
                    op_nums.pop();
                    int op1 = op_nums.top();
                    op_nums.pop();

                    if (_op == '*') {
                        op1 *= op2;
                    } else {
                        op1 /= op2;
                    }
                    
                    op_nums.push(op1);
                }
                if (N) {
                    ops.push(op);
                }
                op = '/';
            } else if (op == '/') {
                while (op_nums.size() > 1 && (ops.top() == '*' || ops.top() == '/')) {
                    char _op = ops.top();
                    ops.pop();
                    int op2 = op_nums.top();
                    op_nums.pop();
                    int op1 = op_nums.top();
                    op_nums.pop();

                    if (_op == '*') {
                        op1 *= op2;
                    } else {
                        op1 /= op2;
                    }
                    
                    op_nums.push(op1);
                }
                if (N) {
                    ops.push(op);
                }
                op = '+';
            } else if (op == '+') {
                while (op_nums.size() > 1) {
                    char _op = ops.top();
                    ops.pop();
                    int op2 = op_nums.top();
                    op_nums.pop();
                    int op1 = op_nums.top();
                    op_nums.pop();

                    if (_op == '*') {
                        op1 *= op2;
                    } else if (_op == '/') {
                        op1 /= op2;
                    } else if (_op == '+') {
                        op1 += op2;
                    } else {
                        op1 -= op2;
                    }
                    
                    op_nums.push(op1);
                }
                if (N) {
                    ops.push(op);
                }
                op = '-';
            } else if (op == '-') {
                while (op_nums.size() > 1) {
                    char _op = ops.top();
                    ops.pop();
                    int op2 = op_nums.top();
                    op_nums.pop();
                    int op1 = op_nums.top();
                    op_nums.pop();

                    if (_op == '*') {
                        op1 *= op2;
                    } else if (_op == '/') {
                        op1 /= op2;
                    } else if (_op == '+') {
                        op1 += op2;
                    } else {
                        op1 -= op2;
                    }
                    
                    op_nums.push(op1);
                }
                if (N) {
                    ops.push(op);
                }
                op = '*';
            }

            if (N) {
                op_nums.push(N--);
            }
        }

        return op_nums.top();
    }
};

int main()
{
    Solution s;

    assert(1 == s.clumsy(1));
    
    assert(7 == s.clumsy(4));

    assert(12 == s.clumsy(10));

    return 0;
}
