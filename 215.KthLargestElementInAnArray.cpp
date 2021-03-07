/**
 * @author Mr Dk.
 * @version 2021/03/07
 */

/*
    Given an integer array nums and an integer k, return the kth largest
    element in the array.

    Note that it is the kth largest element in the sorted order, not the
    kth distinct element. 

    Example 1:
        Input: nums = [3,2,1,5,6,4], k = 2
        Output: 5

    Example 2:
        Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
        Output: 4

    Constraints:
        1 <= k <= nums.length <= 104
        -104 <= nums[i] <= 104

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    借用快速排序的模式进行搜素，每次可以排除一半数据。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
    int binary_find(vector<int> &nums, int low, int high, int k) {
        int _low = low;
        int _high = high;
        int pivot = nums[_low];
        while (_low < _high) {
            while (_low < _high && nums[_high] < pivot) {
                _high--;
            }
            nums[_low] = nums[_high];
            while (_low < _high && nums[_low] >= pivot) {
                _low++;
            }
            nums[_high] = nums[_low];
        }
        nums[_low] = pivot;

        if (_low - low + 1 == k) {
            return nums[_low];
        } else if (_low - low >= k) {
            return binary_find(nums, low, _low - 1, k);
        } else {
            return binary_find(nums, _low + 1, high, k - (_low - low + 1));
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return binary_find(nums, 0, nums.size() - 1, k);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    
    nums = { 3,2,1,5,6,4 };
    assert(5 == s.findKthLargest(nums, 2));

    nums = { 3,2,3,1,2,4,5,5,6 };
    assert(4 == s.findKthLargest(nums, 4));
    
    return 0;
}
