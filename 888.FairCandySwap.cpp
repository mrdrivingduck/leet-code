/**
 * @author Mr Dk.
 * @version 2021/02/01
 */

/*
    Alice and Bob have candy bars of different sizes: A[i] is the size
    of the i-th bar of candy that Alice has, and B[j] is the size of
    the j-th bar of candy that Bob has.

    Since they are friends, they would like to exchange one candy bar
    each so that after the exchange, they both have the same total amount
    of candy.  (The total amount of candy a person has is the sum of the
    sizes of candy bars they have.)

    Return an integer array ans where ans[0] is the size of the candy bar
    that Alice must exchange, and ans[1] is the size of the candy bar that
    Bob must exchange.

    If there are multiple answers, you may return any one of them.  It is
    guaranteed an answer exists. 

    Example 1:
        Input: A = [1,1], B = [2,2]
        Output: [1,2]

    Example 2:
        Input: A = [1,2], B = [2,3]
        Output: [1,2]

    Example 3:
        Input: A = [2], B = [1,3]
        Output: [2,3]

    Example 4:
        Input: A = [1,2,5], B = [2,4]
        Output: [5,4]

    Note:
        1 <= A.length <= 10000
        1 <= B.length <= 10000
        1 <= A[i] <= 100000
        1 <= B[i] <= 100000
        It is guaranteed that Alice and Bob have different total amounts of candy.
        It is guaranteed there exists an answer.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/fair-candy-swap
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    根据两人各自的糖果和，计算出两人需要交换的糖果之间的差值。
    然后在序列中寻找满足该差值的糖果是否存在即可。两种方式：
        1. 将一个人的所有糖果建立 hash table 以便快速查找
        2. 将一个人的所有糖果排序，并使用二分查找
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
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = 0;
        int sum2 = 0;
        for (size_t i = 0; i < A.size(); i++) {
            sum1 += A[i];
        }
        for (size_t i = 0; i < B.size(); i++) {
            sum2 += B[i];
        }

        int delta = (sum2 - sum1) / 2;

        std::sort(B.begin(), B.end());
        for (size_t i = 0; i < A.size(); i++) {
            // find if (A[i] + delta) exists in B.
            if (std::binary_search(B.begin(), B.end(), A[i] + delta)) {
                return { A[i], A[i] + delta };
            }
        }

        return { 0, 0 };
    }
};

int main()
{
    Solution s;
    vector<int> A;
    vector<int> B;
    vector<int> result;

    A = { 1,1 };
    B = { 2,2 };
    result = { 1,2 };
    assert(result == s.fairCandySwap(A, B));

    A = { 1,2 };
    B = { 2,3 };
    result = { 1,2 };
    assert(result == s.fairCandySwap(A, B));

    A = { 2 };
    B = { 1,3 };
    result = { 2,3 };
    assert(result == s.fairCandySwap(A, B));

    A = { 1,2,5 };
    B = { 2,4 };
    result = { 5,4 };
    assert(result == s.fairCandySwap(A, B));
    
    return 0;
}
