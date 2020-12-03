/**
 * @author Mr Dk.
 * @version 2020/12/03
 */

/*
    Count the number of prime numbers less than a non-negative number, n.

    Example 1:
        Input: n = 10
        Output: 4
        Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

    Example 2:
        Input: n = 0
        Output: 0

    Example 3:
        Input: n = 1
        Output: 0

    Constraints:
        0 <= n <= 5 * 106

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/count-primes
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    埃氏筛 - 古老的素数筛选法：
    https://pic.leetcode-cn.com/1606932458-HgVOnW-Sieve_of_Eratosthenes_animation.gif

    初始化一个全为 true 的数组，从下标 2 开始，每一个数组值为 true 的下标就是一个素数，统计；将这
    个素数的所有倍数下标对应的数组元素全部赋值为 false。

    原生数组比 vector 快很多！
 */

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }

        bool *is_prime = new bool[n];
        for (int i = 0; i < n; i++) {
            is_prime[i] = true;
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                count++;

                for (int j = (i << 1); j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        delete[] is_prime;
        return count;
    }
};

int main()
{
    Solution s;

    cout << s.countPrimes(10) << endl;
    cout << s.countPrimes(0) << endl;
    cout << s.countPrimes(1) << endl;
    cout << s.countPrimes(2) << endl;
    cout << s.countPrimes(3) << endl; // [2]
    cout << s.countPrimes(4) << endl; // [2,3]
    cout << s.countPrimes(5) << endl; // [2,3]
    cout << s.countPrimes(499979) << endl;

    return 0;
}