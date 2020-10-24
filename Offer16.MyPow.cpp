/**
 * @author Mr Dk.
 * @version 2020/10/24
 */

/*
    实现函数double Power(double base, int exponent)，求base的exponent次方。
    不得使用库函数，同时不需要考虑大数问题。

    示例 1:

    输入: 2.00000, 10
    输出: 1024.00000

    示例 2:

    输入: 2.10000, 3
    输出: 9.26100

    示例 3:

    输入: 2.00000, -2
    输出: 0.25000
    解释: 2-2 = 1/22 = 1/4 = 0.25
     
    说明:

    -100.0 < x < 100.0
    n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    快速幂。本质上是为了减少乘法的次数。如 7^4，朴素算法需要进行 3 次乘法，而分割成 (7^2)^2
    就只需要两次。节约的乘法次数随着幂次的增大而增多。(O(N) --> O(log(N)))
*/

#include <iostream>
#include <limits.h>

using std::cout;
using std::endl;

class Solution {
public:
    double myPow(double x, int n) {
        // 任何数的 0 次方都为 1
        if (n == 0) {
            return 1;
        }

        // 处理 2147483648 的情况，这个数 >> 1 会发生溢出
        if (n == INT_MIN) {
            double d = myPow(x, n / 2);
            return d * d;
        }

        // 将负数处理为正数
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }

        // 递归出口
        double sub;
        if (n >> 1 == 1) {
            sub = x;
        } else {
            sub = myPow(x, n >> 1);
        }

        // 偶数：x^(n >> 1) * x^(n >> 1)
        // 奇数：x^(n >> 1) * x^(n >> 1) * x
        sub *= sub;
        if (n & 1) {
            return x * sub;
        }
        
        return sub;
    }
};

int main()
{
    Solution s;
    
    cout << 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5.0 << endl;
    cout << s.myPow(5, 10) << endl;

    cout << s.myPow(2, -2) << endl;

    return 0;
}