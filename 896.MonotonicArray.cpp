/**
 * @author Mr Dk.
 * @version 2021/02/28
 */

/*
    An array is monotonic if it is either monotone increasing or monotone
    decreasing.

    An array A is monotone increasing if for all i <= j, A[i] <= A[j].
    An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

    Return true if and only if the given array A is monotonic.

    Example 1:
        Input: [1,2,2,3]
        Output: true

    Example 2:
        Input: [6,5,4,4]
        Output: true

    Example 3:
        Input: [1,3,2]
        Output: false

    Example 4:
        Input: [1,2,4,5]
        Output: true

    Example 5:
        Input: [1,1,1]
        Output: true

    Note:
        1 <= A.length <= 50000
        -100000 <= A[i] <= 100000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/monotonic-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    依次检查数组相邻元素之间的差值。
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
    bool isMonotonic(vector<int>& A) {
        int flag = 0;
        for (size_t i = 0; i < A.size() - 1; i++) {
            if ((A[i] < A[i + 1] && flag > 0) || (A[i] > A[i + 1] && flag < 0)) {
                return false;
            } else if (A[i] != A[i + 1]) {
                flag = A[i] < A[i + 1] ? -1 : 1;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<int> A;

    A = { 1,2,2,3 };
    assert(true == s.isMonotonic(A));

    A = { 6,5,4,4 };
    assert(true == s.isMonotonic(A));

    A = { 1,3,2 };
    assert(false == s.isMonotonic(A));

    A = { 1,2,4,5 };
    assert(true == s.isMonotonic(A));

    A = { 1,1,1 };
    assert(true == s.isMonotonic(A));

    return 0;
}
