/**
 * @author Mr Dk.
 * @version 2021/02/08
 */

/*
    Given an integer array arr, return the length of a maximum size
    turbulent subarray of arr.

    A subarray is turbulent if the comparison sign flips between
    each adjacent pair of elements in the subarray.

    More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of
    arr is said to be turbulent if and only if:

    For i <= k < j:
        arr[k] > arr[k + 1] when k is odd, and
        arr[k] < arr[k + 1] when k is even.
    Or, for i <= k < j:
        arr[k] > arr[k + 1] when k is even, and
        arr[k] < arr[k + 1] when k is odd. 

    Example 1:
        Input: arr = [9,4,2,10,7,8,8,1,9]
        Output: 5
        Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

    Example 2:
        Input: arr = [4,8,12,16]
        Output: 2

    Example 3:
        Input: arr = [100]
        Output: 1

    Constraints:
        1 <= arr.length <= 4 * 104
        0 <= arr[i] <= 109

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-turbulent-subarray
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    滑动窗口。
    
    注意滑动窗口收缩的时机：由于要求被破坏后，整个序列都不满足要求，因此滑动窗口
    左端需要一次性收缩至滑动窗口的右端。
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
    int maxTurbulenceSize(vector<int>& arr) {
        int comparator = 0;
        int max_len = 0;

        size_t left = 0;
        size_t right = 0;
        while (right < arr.size()) {
            if (max_len) {
                int delta = arr[right] - arr[right - 1];

                if (!delta) {
                    left = right;
                } else if (comparator &&
                        ((delta < 0 && comparator < 0) || (delta > 0 && comparator > 0))) {
                    left = right - 1;
                }

                comparator = delta;
            }

            max_len = std::max(max_len, (int) (right - left + 1));
            right++;
        }

        return max_len;
    }
};

int main()
{
    Solution s;
    vector<int> arr;

    arr = { 2,0,2,4,2,5,0,1,2,3 };
    assert(6 == s.maxTurbulenceSize(arr));

    arr = { 9,9 };
    assert(1 == s.maxTurbulenceSize(arr));

    arr = { 9,4,2,10,7,8,8,1,9 };
    assert(5 == s.maxTurbulenceSize(arr));

    arr = { 4,8,12,16 };
    assert(2 == s.maxTurbulenceSize(arr));

    arr = { 100 };
    assert(1 == s.maxTurbulenceSize(arr));

    return 0;
}
