/**
 * @author Mr Dk.
 * @version 2021/01/22
 */

/*
    For a non-negative integer X, the array-form of X is an array of its
    digits in left to right order.  For example, if X = 1231, then the
    array form is [1,2,3,1].

    Given the array-form A of a non-negative integer X, return the
    array-form of the integer X+K.

    Example 1:
        Input: A = [1,2,0,0], K = 34
        Output: [1,2,3,4]
        Explanation: 1200 + 34 = 1234

    Example 2:
        Input: A = [2,7,4], K = 181
        Output: [4,5,5]
        Explanation: 274 + 181 = 455

    Example 3:
        Input: A = [2,1,5], K = 806
        Output: [1,0,2,1]
        Explanation: 215 + 806 = 1021

    Example 4:
        Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
        Output: [1,0,0,0,0,0,0,0,0,0,0]
        Explanation: 9999999999 + 1 = 10000000000

    Note：
        1 <= A.length <= 10000
        0 <= A[i] <= 9
        0 <= K <= 10000
        If A.length > 1, then A[0] != 0

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    将要加的数字拆成数组，然后从数组的最低位开始，按位相加，并保留进位到下一位上。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        std::reverse(A.begin(), A.end());

        vector<int> k_array;
        while (K != 0) {
            k_array.push_back(K % 10);
            K /= 10;
        }

        int flag = 0;
        size_t i = 0;
        while (i < A.size()) {
            if (i < k_array.size()) {
                A[i] += k_array[i];
            }
            A[i] += flag;

            if (A[i] >= 10) {
                A[i] -= 10;
                flag = 1;
            } else {
                flag = 0;
            }

            i++;
        }

        while (i < k_array.size()) {
            int new_bit = k_array[i] + flag;
            if (new_bit >= 10) {
                new_bit -= 10;
                flag = 1;
            } else {
                flag = 0;
            }

            A.push_back(new_bit);
            i++;
        }

        if (flag > 0) {
            A.push_back(flag);
        }

        std::reverse(A.begin(), A.end());
        return A;
    }
};

int main()
{
    Solution s;
    vector<int> number_array;
    vector<int> result_array;

    number_array = { 1,2,0,0 };
    result_array = { 1,2,3,4 };
    assert(result_array == s.addToArrayForm(number_array, 34));

    number_array = { 2,7,4 };
    result_array = { 4,5,5 };
    assert(result_array == s.addToArrayForm(number_array, 181));

    number_array = { 2,1,5 };
    result_array = { 1,0,2,1 };
    assert(result_array == s.addToArrayForm(number_array, 806));

    number_array = { 9,9,9,9,9,9,9,9,9,9 };
    result_array = { 1,0,0,0,0,0,0,0,0,0,0 };
    assert(result_array == s.addToArrayForm(number_array, 1));

    return 0;
}
