/**
 * @author Mr Dk.
 * @version 2021/03/06
 */

/*
    Given a circular array (the next element of the last element is the
    first element of the array), print the Next Greater Number for every
    element. The Next Greater Number of a number x is the first greater
    number to its traversing-order next in the array, which means you
    could search circularly to find its next greater number. If it
    doesn't exist, output -1 for this number.

    Example 1:
        Input: [1,2,1]
        Output: [2,-1,2]
        Explanation:
            The first 1's next greater number is 2; 
            The number 2 can't find next greater number; 
            The second 1's next greater number needs to search circularly,
            which is also 2.

    Note: The length of given array won't exceed 10000.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/next-greater-element-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    单调栈，维护当前没有遇到更大值的数组元素的 “下标”。每遍历到一个数组元素时，
    先于栈顶下标所对应的元素比较：如果大于栈顶，则不断弹栈，并将弹出下标对应的
    更大值设置为当前数组元素；如果小于等于栈顶，则压栈。

    需要遍历两轮，以保证每个元素都在数组中搜索了一轮。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> next_greater_elements(nums.size(), -1);
        vector<int> stack;

        for (size_t i = 0; i < (nums.size() << 1); i++) {
            while (!stack.empty() && nums[i % nums.size()] > nums[stack[stack.size() - 1]]) {
                next_greater_elements[stack[stack.size() - 1]] = nums[i % nums.size()];
                stack.pop_back();
            }
            stack.push_back(i % nums.size());
        }

        return next_greater_elements;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    vector<int> result;

    nums = { 1,2,1 };
    result = { 2,-1,2 };
    assert(result == s.nextGreaterElements(nums));

    return 0;
}
