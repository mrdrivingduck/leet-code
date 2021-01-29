/**
 * @author Mr Dk.
 * @version 2021/01/29
 */

/*
    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
    输入一个数组，求出这个数组中的逆序对的总数。

    示例 1:
        输入: [7,5,6,4]
        输出: 5

    限制：
        0 <= 数组长度 <= 50000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    在归并排序的过程中顺便计算逆序对数。
*/

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
private:
    int merge_sort(vector<int> &nums, size_t left, size_t left_len, size_t right_len) {
        int reverse = 0;

        if (left_len > 1) {
            size_t left_left_len = left_len >> 1;
            reverse += merge_sort(nums, left, left_left_len, left_len - left_left_len);
        }
        if (right_len > 1) {
            size_t right_left_len = right_len >> 1;
            reverse += merge_sort(nums, left + left_len, right_left_len, right_len - right_left_len);
        }

        vector<int> sorted;
        size_t i = 0, j = 0;
        while (i < left_len && j < right_len) {
            if (nums[left + i] <= nums[left + left_len + j]) {
                sorted.push_back(nums[left + i]);
                i++;
                reverse += j;
            } else {
                sorted.push_back(nums[left + left_len + j]);
                j++;
            }
        }
        while (i < left_len) {
            sorted.push_back(nums[left + i]);
            i++;
            reverse += j;
        }
        while (j < right_len) {
            sorted.push_back(nums[left + left_len + j]);
            j++;
        }

        std::copy(sorted.begin(), sorted.begin() + left_len + right_len, nums.begin() + left);

        return reverse;
    }

public:
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size(), 0);
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 7,5,6,4 };
    
    assert(5 == s.reversePairs(nums));

    return 0;
}
