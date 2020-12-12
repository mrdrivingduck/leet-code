/**
 * @author Mr Dk.
 * @version 2020/12/12
 */

/*
    A sequence of numbers is called a wiggle sequence if the differences
    between successive numbers strictly alternate between positive and
    negative. The first difference (if one exists) may be either positive
    or negative. A sequence with fewer than two elements is trivially a
    wiggle sequence.

    For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
    (6,-3,5,-7,3) are alternately positive and negative. In contrast,
    [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because
    its first two differences are positive and the second because its last
    difference is zero.

    Given a sequence of integers, return the length of the longest subsequence
    that is a wiggle sequence. A subsequence is obtained by deleting some
    number of elements (eventually, also zero) from the original sequence,
    leaving the remaining elements in their original order.

    Example 1:
        Input: [1,7,4,9,2,5]
        Output: 6
        Explanation: The entire sequence is a wiggle sequence.

    Example 2:
        Input: [1,17,5,10,13,15,10,5,16,8]
        Output: 7
        Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

    Example 3:
        Input: [1,2,3,4,5,6,7,8,9]
        Output: 2

    Follow up:
        Can you do it in O(n) time?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/wiggle-subsequence
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    使用一个一维数组 + 动态规划来解决。数组中每个元素的含义是，当前长度
    的数列下的最长摆动序列。其中，[0] 的最长摆动序列长度为 1，数组中的
    最后一个元素就是整个序列的最长摆动长度。

    首先过滤掉一个情况：如果一个数与前一个数相同，那么最长摆动序列的长度
    肯定不变。
    其次，需要用一个变量来记录，目前应该使得摆动序列的增长应当是递增还是
    递减。这需要用最前面的两个不等相邻数决定。每当序列增加一个元素时，如果
    这个元素符合递增或递减要求，那么最长摆动长度就比前一个最长摆动长度 + 1。
    否则最长摆动长度不变，逻辑上相当于丢弃了一个元素。

    这里面蕴含一个贪心的策略：希望摆动的幅度越大越好。摆动的幅度越大，那么摆动
    序列能够接受下一个值的概率就越大。比如，[5,10] 后下一个元素应当接受递减
    的数，而如果下一个数是 13 (比 10 大)，那么虽然最长摆动长度没有变，但
    还是应该让更大的数进入摆动序列，即 [5,13]。如果再下一个数是 11，那么
    [5,13] 是可以接受这个数进入摆动序列的，而 [5,10] 就不行。因此，在每次
    判断下一个数是否符合要求时，只需要和前一个数进行比较即可，可能有两种情况：

    1. 不满足递增 / 递减，最大摆动长度不变，这个数替代了原来的最后一个数进入
        摆动序列，因为它能使摆动幅度变大 (递减时越小越好，递增时越大越好)
    2. 满足递增 / 递减，最大摆动长度 + 1，这个数进入摆动序列而成为了新的转折点
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // initialize array for DP
        vector<int> length(nums.size());
        length[0] = 1;

        if (nums.size() > 1) {
            bool up; // no decided yet
            bool init = false; // used only once

            for (size_t i = 1; i < nums.size(); i++) {
                if (nums[i] == nums[i - 1]) {
                    length[i] = length[i - 1];
                    continue;
                }

                if (!init) {
                    // initial tendency
                    up = nums[i - 1] < nums[i];
                    init = true;
                }

                if ((nums[i] > nums[i - 1] && up) ||
                    (nums[i] < nums[i - 1] && !up)) {
                    // new turning point
                    // flip the tendency
                    length[i] = length[i - 1] + 1;
                    up = !up;
                } else {
                    length[i] = length[i - 1];
                    // (logically) replace the last element
                    // with the current element in the sequence
                }
            }
        }

        return length[length.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 1,2,3,4,5,6,7,8,9 };
    cout << s.wiggleMaxLength(nums) << endl;

    nums = { 2,2,2,1,3,4,5,6,7,8,9 };
    cout << s.wiggleMaxLength(nums) << endl;

    nums = { 1,17,5,10,13,15,10,5,16,8 };
    cout << s.wiggleMaxLength(nums) << endl;

    nums = { 1,7,4,9,2,5 };
    cout << s.wiggleMaxLength(nums) << endl;

    return 0;
}
