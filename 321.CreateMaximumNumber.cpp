/**
 * @author Mr Dk.
 * @version 2020/12/02
 */

/*
    Given two arrays of length m and n with digits 0-9 representing two
    numbers. Create the maximum number of length k <= m + n from digits
    of the two. The relative order of the digits from the same array must
    be preserved. Return an array of the k digits.

    Note: You should try to optimize your time and space complexity.

    Example 1:
        Input:
            nums1 = [3, 4, 6, 5]
            nums2 = [9, 1, 2, 5, 8, 3]
            k = 5
        Output:
            [9, 8, 6, 5, 3]

    Example 2:
        Input:
            nums1 = [6, 7]
            nums2 = [6, 0, 4]
            k = 5
        Output:
            [6, 7, 6, 0, 4]

    Example 3:
        Input:
            nums1 = [3, 9]
            nums2 = [8, 9]
            k = 3
        Output:
            [9, 8, 9]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/create-maximum-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    分别求出两个数组所有长度组合的单调递减子序列，然后以字典序最大的规则拼接。
    最核心的三个步骤：
        1. 求任意长度的单调递减子序列 (单调栈实现方式)
        2. 数组的字典序比较
        3. 数组的字典序合并
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
private:

    /**
     * Sort two arrays in dictionary order.
     * If the content are the same, then compare the length.
     */
    bool compare(vector<int>::iterator begin_1, vector<int>::iterator end_1,
                    vector<int>::iterator begin_2, vector<int>::iterator end_2) {
        if (begin_1 != end_1 && begin_2 != end_2) {
            while (begin_1 != end_1 && begin_2 != end_2) {
                if (*begin_1 == *begin_2) {
                    begin_1++;
                    begin_2++;
                    continue;
                }

                return *begin_1 < *begin_2;
            }
        }

        // length compare
        // including nums1.empty() || nums2.empty()
        return end_1 - begin_1 < end_2 - begin_2;
    }

    vector<int> decending_stack(vector<int> &source, int capacity) {
        // capacity <= source.size()

        vector<int> stack;
        stack.reserve(capacity);

        if (capacity <= 0 || capacity > (int) source.size()) {
            return stack;
        }

        for (size_t i = 0; i < source.size(); i++) {
            if (stack.empty()) {
                stack.push_back(source[i]);
            } else if (source[i] <= stack[stack.size() - 1]) {
                if (stack.size() < (size_t) capacity) {
                    stack.push_back(source[i]);
                }
            } else {
                while (!stack.empty() &&
                        source[i] > stack[stack.size() - 1] &&
                        stack.size() + source.size() - i > (size_t) capacity) {
                    // stack element + (remaining element) > stack capacity
                    stack.pop_back();
                }
                stack.push_back(source[i]);
            }
        }

        return stack;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> max;
        max.reserve(k);

        for (size_t i = 0, j = k - i; i <= (size_t) k /* attention */; i++, j--) {
            // to enumerate all possible combination of i and j
            // from i == 0, to j == 0
            // but j is an unsigned number, so condition should be i <= k

            vector<int> decend_1 = decending_stack(nums1, i);
            if (decend_1.size() != i) {
                continue;
            }
            vector<int> decend_2 = decending_stack(nums2, j);
            if (decend_2.size() != j) {
                continue;
            }

            // merge two decending stack
            vector<int>::iterator iter_1 = decend_1.begin();
            vector<int>::iterator iter_2 = decend_2.begin();
            vector<int> temp;
            temp.reserve(k);
            while (iter_1 != decend_1.end() && iter_2 != decend_2.end()) {
                // if the current number is the same
                // then following numbers should be compared, until the end
                if (compare(iter_1, decend_1.end(), iter_2, decend_2.end())) {
                    temp.push_back(*iter_2);
                    iter_2++;
                } else {
                    temp.push_back(*iter_1);
                    iter_1++;
                }
            }
            if (iter_1 != decend_1.end()) {
                temp.insert(temp.end(), iter_1, decend_1.end());
            }
            if (iter_2 != decend_2.end()) {
                temp.insert(temp.end(), iter_2, decend_2.end());
            }

            // larget than maximum sequence
            if (compare(max.begin(), max.end(), temp.begin(), temp.end())) {
                max = temp;
            }
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums1, nums2, max;

    nums1 = { 2,5,6,4,4,0 };
    nums2 = { 7,3,8,0,6,5,7,6,2 };
    max = s.maxNumber(nums1, nums2, 15);
    for (size_t i = 0; i < max.size(); i++) {
        cout << max[i] << " ";
    }
    cout << endl;

    nums1 = { 3,4,8,9,3,0 };
    nums2 = { 6,1,9,1,1,2 };
    max = s.maxNumber(nums1, nums2, 6);
    for (size_t i = 0; i < max.size(); i++) {
        cout << max[i] << " ";
    }
    cout << endl;

    nums1 = { 3,4,6,5 };
    nums2 = { 9,1,2,5,8,3 };
    max = s.maxNumber(nums1, nums2, 5);
    for (size_t i = 0; i < max.size(); i++) {
        cout << max[i] << " ";
    }
    cout << endl;

    nums1 = { 6,7 };
    nums2 = { 6,0,4 };
    max = s.maxNumber(nums1, nums2, 5);
    for (size_t i = 0; i < max.size(); i++) {
        cout << max[i] << " ";
    }
    cout << endl;

    nums1 = { 3,9 };
    nums2 = { 8,9 };
    max = s.maxNumber(nums1, nums2, 3);
    for (size_t i = 0; i < max.size(); i++) {
        cout << max[i] << " ";
    }
    cout << endl;

    nums1 = {  };
    nums2 = { 1 };
    max = s.maxNumber(nums1, nums2, 1);
    for (size_t i = 0; i < max.size(); i++) {
        cout << max[i] << " ";
    }
    cout << endl;

    nums1 = { 1,2 };
    nums2 = {  };
    max = s.maxNumber(nums1, nums2, 2);
    for (size_t i = 0; i < max.size(); i++) {
        cout << max[i] << " ";
    }
    cout << endl;

    return 0;
}
