/**
 * @author Mr Dk.
 * @version 2019.08.06
 */

/*
    There are two sorted arrays nums1 and nums2 of size m and n respectively.

    Find the median of the two sorted arrays.
    The overall run time complexity should be O(log (m+n)).

    You may assume nums1 and nums2 cannot be both empty.

    Example 1:

    nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0
    Example 2:

    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    寻找第 k 小的数 - 特殊情况 - 寻找第 (l1 + l2) / 2 小的数
    找两个数组第 k / 2 小的数
    如果数组 A 的第 k / 2 小的数 < 数组 B 的第 k / 2 小的数
    那么数组 A 的前 k / 2 小的数肯定不是第 k 小的数，从而被排除
    将数组 A 的前 k / 2 小的数移除后，将 k 扣除移除后的数量 (k / 2)
    再重复上述过程

    可能有一个数组为空
    
    二分 - 复杂度为 O(log(m + n))
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned long total = nums1.size() + nums2.size();
        unsigned long k = (total % 2) ? total / 2 : (total - 1) / 2;

        if (total % 2) { // 奇数
            return findSmall(nums1, nums2, 0, 0, k);
        } else { // 偶数
            double sum = findSmall(nums1, nums2, 0, 0, k) + findSmall(nums1, nums2, 0, 0, k + 1);
            return sum / 2;
        }
    }
    int findSmall(vector<int>& nums1, vector<int>& nums2, unsigned long head1, unsigned long head2, unsigned long k) {
        if (k == 0) {
            if (head1 >= nums1.size()) {
                return nums2[head2];
            }
            if (head2 >= nums2.size()) {
                return nums1[head1];
            }
            return nums1[head1] < nums2[head2] ? nums1[head1] : nums2[head2];
        }
        if (head1 + k / 2 >= nums1.size()) {
            return nums2[head2 + k - (nums1.size() - head1)];
        }
        if (head2 + k / 2 >= nums2.size()) {
            return nums1[head1 + k - (nums2.size() - head2)];
        }
        if (nums1[head1 + k / 2] < nums2[head2 + k / 2]) {
            if (head1 + k / 2 + 1 >= nums1.size()) {
                return nums2[head2 + k - k / 2 - 1];
            } else {
                return findSmall(nums1, nums2, head1 + k / 2 + 1, head2, k - k / 2 - 1);
            }
        } else {
            if (head2 + k / 2 + 1 >= nums2.size()) {
                return nums1[head1 + k - k / 2 - 1];
            } else {
                return findSmall(nums1, nums2, head1, head2 + k / 2 + 1, k - k / 2 - 1);
            }
        }
    }
};

int main() {

    vector<int> v1;
    vector<int> v2;

    Solution solution;

    // v1.push_back(1);
    // v1.push_back(3);
    // v2.push_back(2);

    v1.push_back(1);
    v1.push_back(1);
    v2.push_back(1);
    v2.push_back(1);

    // v1.push_back(1);
    // v1.push_back(2);
    // v2.push_back(3);
    // v2.push_back(4);
    // v2.push_back(5);
    // v2.push_back(6);

    cout << solution.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}
