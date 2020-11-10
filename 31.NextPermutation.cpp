/**
 * @author Mr Dk.
 * @version 2020.11.10
 */

/*
    Implement next permutation, which rearranges numbers into the
    lexicographically next greater permutation of numbers.

    If such an arrangement is not possible, it must rearrange it
    as the lowest possible order (i.e., sorted in ascending order).

    The replacement must be in place and use only constant extra memory. 

    Example 1:

    Input: nums = [1,2,3]
    Output: [1,3,2]

    Example 2:

    Input: nums = [3,2,1]
    Output: [1,2,3]

    Example 3:
    Input: nums = [1,1,5]
    Output: [1,5,1]

    Example 4:
    Input: nums = [1]
    Output: [1]

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/next-permutation
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    找到全排列中下一个字典序的排序。下一字典序意味着尽可能长的公共子前缀。
    从数组的末尾开始寻找第一处 [前一个数 (i) 小于后一个数 (j)] 的位置，
    这也就意味着从 j 开始的子序列中，存在一个比 i 要大的数 (但不一定是 j)。
    在子序列中寻找比 i 大的最小的数之后，将这个数与 i 交换位置，然后对剩下
    的子序列进行重排序，使这个子序列成为字典序最小的全排序。

    如，对 1,2,4,6,5,3 来说，4 和 6 就是要找的位置，这意味着 6,5,3 中
    肯定存在一个比 4 大的数，目前 4 的位置也是公共子序列的最长处。所以从
    6,5,3 中找到了比 4 大的最小数 5，交换位置后为：1,2,5,6,4,3。下一个
    字典序公共子前缀已经更新为 1,2,5，所以之后的子序列要恢复到最小的字典序，
    因此对子序列进行全排序，得到 1,2,5,3,4,6。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::size_t;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        j = nums.size() - 1;
        i = j - 1;

        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }

        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        for (size_t k = j; k < nums.size(); k++) {
            if (nums[k] > nums[i] && nums[k] < nums[j]) {
                j = k;
            }
        }

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;

        sort(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution s;

    vector<int> v = { 1,2,3 };
    s.nextPermutation(v);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v = { 3,2,1 };
    s.nextPermutation(v);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v = { 1,1,5 };
    s.nextPermutation(v);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v = { 1 };
    s.nextPermutation(v);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v = { 5,1,1 };
    s.nextPermutation(v);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v = { 1,2,4,6,5,3 };
    s.nextPermutation(v);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
