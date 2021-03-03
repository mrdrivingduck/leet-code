/**
 * @author Mr Dk.
 * @version 2021/03/03
 */

/*
    Given a non negative integer number num. For every numbers i in the
    range 0 ≤ i ≤ num calculate the number of 1's in their binary
    representation and return them as an array.

    Example 1:
        Input: 2
        Output: [0,1,1]

    Example 2:
        Input: 5
        Output: [0,1,1,2,1,2]

    Follow up:
        It is very easy to come up with a solution with run time
        O(n*sizeof(integer)). But can you do it in linear time
        O(n) /possibly in a single pass?
        Space complexity should be O(n).
        Can you do it like a boss? Do it without using any builtin
        function like __builtin_popcount in c++ or in any other language.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/counting-bits
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    实际上是一道动态规划题。根据奇数和偶数的二进制表示的性质，使用之前
    已经得出的二进制数量的结果。奇数之比前一个偶数多了一个 1；偶数与
    小一半的数的 1 的个数相同。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            if (i & 1) {
                bits[i] = bits[i - 1] + 1;
            } else {
                bits[i] = bits[i >> 1];
            }
        }

        return bits;
    }
};

int main()
{
    Solution s;
    vector<int> bits;

    bits = { 0,1,1 };
    assert(bits == s.countBits(2));

    bits = { 0,1,1,2,1,2 };
    assert(bits == s.countBits(5));

    return 0;
}
