/**
 * @author Mr Dk.
 * @version 2021/03/22
 */

/*
    Write a function that takes an unsigned integer and returns the number
    of '1' bits it has (also known as the Hamming weight).

    Note:

    Note that in some languages, such as Java, there is no unsigned integer
    type. In this case, the input will be given as a signed integer type. It
    should not affect your implementation, as the integer's internal binary
    representation is the same, whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement
    notation. Therefore, in Example 3, the input represents the signed
    integer. -3. 

    Example 1:
        Input: n = 00000000000000000000000000001011
        Output: 3
        Explanation:
            The input binary string 00000000000000000000000000001011 has a
            total of three '1' bits.

    Example 2:
        Input: n = 00000000000000000000000010000000
        Output: 1
        Explanation:
            The input binary string 00000000000000000000000010000000 has a
            total of one '1' bit.

    Example 3:
        Input: n = 11111111111111111111111111111101
        Output: 31
        Explanation:
            The input binary string 11111111111111111111111111111101 has a
            total of thirty one '1' bits.

    Constraints:
        The input must be a binary string of length 32.

    Follow up:
        If this function is called many times, how would you optimize it?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/number-of-1-bits
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    通过移位运算，依次判断数字的最低位是否为 1。如果是，则计数器累加。
 */

#include <cassert>

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (long unsigned int i = 0; i < sizeof(uint32_t) << 3; i++, n >>= 1) {
            if (n & 1) {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;

    assert(3 == s.hammingWeight(
        std::stoul("00000000000000000000000000001011", 0, 2)
    ));

    assert(1 == s.hammingWeight(
        std::stoul("00000000000000000000000010000000", 0, 2)
    ));

    assert(31 == s.hammingWeight(
        std::stoul("11111111111111111111111111111101", 0, 2)
    ));

    return 0;
}
