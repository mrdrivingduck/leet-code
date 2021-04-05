/**
 * @author Mr Dk.
 * @version 2021/04/05
 */

/*
    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1
    as one sorted array.

    The number of elements initialized in nums1 and nums2 are m and n
    respectively. You may assume that nums1 has a size equal to m + n such
    that it has enough space to hold additional elements from nums2.

    Example 1:
        Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        Output: [1,2,2,3,5,6]

    Example 2:
        Input: nums1 = [1], m = 1, nums2 = [], n = 0
        Output: [1]

    Constraints:
        nums1.length == m + n
        nums2.length == n
        0 <= m, n <= 200
        1 <= m + n <= 200
        -109 <= nums1[i], nums2[i] <= 109

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/merge-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    避免不必要的搬移和空间消耗，可以从 nums1 最后的空间开始用起。
    不断将两个数组中最大的元素放到 nums1 空间的最后。
 */

#include <cassert>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int cur = nums1.size() - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[cur--] = nums1[i--];
            } else {
                nums1[cur--] = nums2[j--];
            }
        }
        while (i >= 0) {
            nums1[cur--] = nums1[i--];
        }
        while (j >= 0) {
            nums1[cur--] = nums2[j--];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums1;
    vector<int> nums2;

    nums1 = { 1,2,3,0,0,0 };
    nums2 = { 2,5,6 };
    s.merge(nums1, 3, nums2, 3);
    nums2 = { 1,2,2,3,5,6 };
    assert(nums1 == nums2);

    nums1 = { 1 };
    nums2 = {  };
    s.merge(nums1, 1, nums2, 0);
    nums2 = { 1 };
    assert(nums1 == nums2);

    nums1 = { 0 };
    nums2 = { 1 };
    s.merge(nums1, 0, nums2, 1);
    nums2 = { 1 };
    assert(nums1 == nums2);

    return 0;
}
