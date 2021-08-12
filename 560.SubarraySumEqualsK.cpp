/**
 * @author Mr Dk.
 * @version 2021/08/12
 */

/*
    Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

    Example 1:
        Input: nums = [1,1,1], k = 2
        Output: 2

    Example 2:
        Input: nums = [1,2,3], k = 3
        Output: 2

    Constraints:
        1 <= nums.length <= 2 * 104
        -1000 <= nums[i] <= 1000
        -107 <= k <= 107

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    计算所有的数组前缀和。任意一个区间的和都是两个端点的前缀和之差。
    对于每一个点 n 来说，如果要找和为 k 的区间数，只需找它前面的前缀和
    出现了几个 sum[n] - k 即可。用一个 multiset 来维护每个点之前的
    所有前缀和，从而实现快速查找。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_multiset;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size() + 1, 0);
        unordered_multiset<int> sums_set;
        sums_set.insert(0);
        int count = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            sums[i + 1] = nums[i] + sums[i];
            count += sums_set.count(sums[i + 1] - k);
            sums_set.insert(sums[i + 1]);
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 1,1,1 };
    assert(2 == s.subarraySum(nums, 2));

    nums = { 1,2,3 };
    assert(2 == s.subarraySum(nums, 3));

    return 0;
}
