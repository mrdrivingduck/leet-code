/**
 * @author Mr Dk.
 * @version 2021/01/27
 */

/*
    Given an integer array arr and a target value target, return the integer
    value such that when we change all the integers larger than value in the
    given array to be equal to value, the sum of the array gets as close as
    possible (in absolute difference) to target.

    In case of a tie, return the minimum such integer.

    Notice that the answer is not neccesarilly a number from arr.

    Example 1:
        Input: arr = [4,9,3], target = 10
        Output: 3
        Explanation:
            When using 3 arr converts to [3, 3, 3] which sums 9 and that's
            the optimal answer.

    Example 2:
        Input: arr = [2,3,5], target = 10
        Output: 5

    Example 3:
        Input: arr = [60864,25176,27249,21296,20204], target = 56803
        Output: 11361

    Constraints:
        1 <= arr.length <= 10^4
        1 <= arr[i], target <= 10^5

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    确定枚举上下界，二分查找。
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
    int findBestValue(vector<int>& arr, int target) {
        std::sort(arr.begin(), arr.end());

        vector<int> sum(arr.size(), arr[0]);
        for (size_t i = 1; i < arr.size(); i++) {
            sum[i] = sum[i - 1] + arr[i];
        }

        int min_delta = INT32_MAX;
        int value = arr[arr.size() - 1];
        for (; value >= 0; value--) {
            int upper = std::upper_bound(arr.begin(), arr.end(), value) - arr.begin();
            int current_sum = (upper > 0) ?
                    sum[upper - 1] + value * (arr.size() - upper) :
                    value * arr.size();
            int delta = current_sum - target;
            if (delta < 0) {
                delta = -delta;
            }

            if (delta <= min_delta) {
                min_delta = delta;
            } else {
                value++;
                break;
            }
        }

        if (value < 0) {
            value++;
        }

        return value;
    }
};

int main()
{
    Solution s;
    vector<int> arr;

    arr = { 4,9,3 };
    assert(3 == s.findBestValue(arr, 10));

    arr = { 2,3,5 };
    assert(5 == s.findBestValue(arr, 10));

    arr = { 60864,25176,27249,21296,20204 };
    assert(11361 == s.findBestValue(arr, 56803));

    return 0;
}
