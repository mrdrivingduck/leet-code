/**
 * @author Mr Dk.
 * @version 2020/11/26
 */

/*
    Given an unsorted array, find the maximum difference between the
    successive elements in its sorted form.

    Return 0 if the array contains less than 2 elements.

    Example 1:
        Input: [3,6,9,1]
        Output: 3
        Explanation: The sorted form of the array is [1,3,6,9], either
                        (3,6) or (6,9) has the maximum difference 3.

    Example 2:
        Input: [10]
        Output: 0
        Explanation: The array contains less than 2 elements, therefore
                        return 0.

    Note:
        You may assume all elements in the array are non-negative
        integers and fit in the 32-bit signed integer range.
        Try to solve it in linear time/space.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximum-gap
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    自实现方式：在快速排序的过程中，顺便计算 pivot 和旁边元素之间的 delta。
    顺便复习了一下快速排序的写法，得默写下来。

    题目要求时间复杂度和空间复杂度为线性，那么需要使用桶排序。反而速度慢了，
    但是复杂度降到了 O(n)。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
private:
    int partition(vector<int> &nums, int low, int high) {
        int pivot_val = nums[low];
        
        while (low < high) {
            while (low < high && nums[high] >= pivot_val) {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot_val) {
                low++;
            }
            nums[high] = nums[low];
        }

        nums[low] = pivot_val; // "low" is the pivot position
        return low;
    }

    void quick_sort(vector<int> &nums, int low, int high, int &delta) {
        int mid = partition(nums, low, high);
        int d;
        if (low < mid - 1) {
            quick_sort(nums, low, mid - 1, delta);
        }
        if (mid + 1 < high) {
            quick_sort(nums, mid + 1, high, delta);
        }

        // calculate maximum delta
        if (mid - 1 >= 0 &&
                (d = nums[mid] - nums[mid - 1]) > delta) {
            delta = d;
        }
        if (mid + 1 < (int) nums.size() &&
                (d = nums[mid + 1] - nums[mid]) > delta) {
            delta = d;
        }
    }

public:
    /**
     * quick sort
     */
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int delta = 0;
        quick_sort(nums, 0, nums.size() - 1, delta);
        return delta;
    }

    /**
     * bucket sort
     */
    // int maximumGap(vector<int>& nums) {
    //     if (nums.size() < 2) {
    //         return 0;
    //     }

    //     // get maximum element
    //     int max = nums[0];
    //     for (size_t i = 1; i < nums.size(); i++) {
    //         if (max < nums[i]) {
    //             max = nums[i];
    //         }
    //     }

    //     // get sorting times
    //     unsigned unit = 1;
    //     int base = 1;
    //     while (unit < max) {
    //         base++;
    //         unit *= 10;
    //     }

    //     // start from the lowest bit
    //     vector<int> buf(nums.size());
    //     unit = 1;

    //     for (int i = 0; i < base; i++) {
    //         vector<int> bucket(10, 0);

    //         // get bucket count
    //         for (size_t j = 0; j < nums.size(); j++) {
    //             bucket[(nums[j] / unit) % 10]++;
    //         }

    //         // end position in array (not included)
    //         for (int j = 1; j < 10; j++) {
    //             bucket[j] += bucket[j - 1];
    //         }

    //         // reverse-order to fill buffer
    //         for (int j = nums.size() - 1; j >= 0; j--) {
    //             int digit = (nums[j] / unit) % 10;
    //             buf[--bucket[digit]] = nums[j];
    //         }

    //         // copy from buf to nums
    //         nums.swap(buf);
    //         unit *= 10;
    //     }

    //     // get maximum delta
    //     int delta = 0;
    //     int d;
    //     for (size_t i = 1; i < nums.size(); i++) {
    //         if ((d = nums[i] - nums[i - 1]) > delta) {
    //             delta = d;
    //         }
    //     }

    //     return delta;
    // }
};

int main()
{
    Solution s;
    vector<int> nums;
    
    nums = { 3,6,9,1 };
    cout << endl << s.maximumGap(nums) << endl;
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    nums = { 1,10000000 };
    cout << endl << s.maximumGap(nums) << endl;
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}