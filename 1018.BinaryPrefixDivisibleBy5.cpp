/**
 * @author Mr Dk.
 * @version 2021/01/14
 */

/*
    Given an array A of 0s and 1s, consider N_i: the i-th subarray from
    A[0] to A[i] interpreted as a binary number (from most-significant-bit
    to least-significant-bit.)

    Return a list of booleans answer, where answer[i] is true if and only
    if N_i is divisible by 5.

    Example 1:
        Input: [0,1,1]
        Output: [true,false,false]
        Explanation: 
            The input numbers in binary are 0, 01, 011; which are 0, 1,
            and 3 in base-10. Only the first number is divisible by 5,
            so answer[0] is true.

    Example 2:
        Input: [1,1,1]
        Output: [false,false,false]

    Example 3:
        Input: [0,1,1,1,1,1]
        Output: [true,false,false,false,true,false]

    Example 4:
        Input: [1,1,1,0,1]
        Output: [false,false,false,false,false]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-prefix-divisible-by-5
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    每次通过移位运算和或运算累加数字，但是每次只保留余数即可，因为 5 和 10 仅和
    最后一位有关。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result(A.size());

        int num = 0;
        for (size_t i = 0; i < A.size(); i++) {
            num <<= 1;
            num |= A[i];

            num %= 5;
            result[i] = !num ? true : false;
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> array;
    vector<bool> dividable;

    dividable = { true, false, false };
    array = { 0,1,1 };
    assert(dividable == s.prefixesDivBy5(array));

    dividable = { false, false, false };
    array = { 1,1,1 };
    assert(dividable == s.prefixesDivBy5(array));

    dividable = { true,false,false,false,true,false };
    array = { 0,1,1,1,1,1 };
    assert(dividable == s.prefixesDivBy5(array));

    dividable = { false,false,false,false,false };
    array = { 1,1,1,0,1 };
    assert(dividable == s.prefixesDivBy5(array));

    return 0;
}
