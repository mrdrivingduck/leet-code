/**
 * @author Mr Dk.
 * @version 2021/01/02
 */

/*
    You are given an array of integers nums, there is a sliding window of
    size k which is moving from the very left of the array to the very right.
    You can only see the k numbers in the window. Each time the sliding
    window moves right by one position.

    Return the max sliding window.

    Example 1:
        Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
        Output: [3,3,5,5,6,7]
        Explanation: 
            Window position                Max
            ---------------               -----
            [1  3  -1] -3  5  3  6  7       3
            1 [3  -1  -3] 5  3  6  7       3
            1  3 [-1  -3  5] 3  6  7       5
            1  3  -1 [-3  5  3] 6  7       5
            1  3  -1  -3 [5  3  6] 7       6
            1  3  -1  -3  5 [3  6  7]      7

    Example 2:
        Input: nums = [1], k = 1
        Output: [1]

    Example 3:
        Input: nums = [1,-1], k = 1
        Output: [1,-1]

    Example 4:
        Input: nums = [9,11], k = 2
        Output: [11]

    Example 5:
        Input: nums = [4,-2], k = 2
        Output: [4]

    Constraints:
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
        1 <= k <= nums.length

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sliding-window-maximum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    实现滑动窗口内的最大值。

    使用一个双向队列维护窗口，窗口内存储的形式是元素在数组内的下标，存储策略是保证队列内
    下标对应的元素大小单调递减。这样，队头元素对应了目前窗口内最大元素的下标，每当窗口
    滑动时，如果队头元素已经不处于窗口范围内，可以通过 pop_front() 立刻将其移除；新的
    元素进入窗口时，需要不停和队尾对应的元素作比较，如果比队尾对应的元素大，就可以不断
    pop_back() 队尾，依此类推直到队列为空或比队尾对应元素小，并将自己的下标放入队列 - 
    这里有点单调栈的思想，即新加入窗口的元素比窗口内已有元素大，那么之后考虑窗口内最大值
    时不再需要考虑比这个新元素更小的那些值了，所以这些值从队尾被安全地 pop_back() 了。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <deque>
using std::cout;
using std::endl;
using std::vector;
using std::deque;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        for (int i = 0; i < k; i++) {
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
        }

        vector<int> max;
        max.push_back(nums[window.front()]);

        for (int i = k; i < (int) nums.size(); i++) {
            // element out of window
            if (!window.empty() && window.front() < i + 1 - k) {
                window.pop_front();
            }
            // pop element smaller than new element
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            // push new element
            window.push_back(i);

            // get maximum value of current window
            max.push_back(nums[window.front()]);
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> expect;

    nums = { 1,3,-1,-3,5,3,6,7 };
    expect = { 3,3,5,5,6,7 };
    assert(expect == s.maxSlidingWindow(nums, 3));

    nums = { 1 };
    expect = { 1 };
    assert(expect == s.maxSlidingWindow(nums, 1));
    
    nums = { 1,-1 };
    expect = { 1,-1 };
    assert(expect == s.maxSlidingWindow(nums, 1));

    nums = { 9,11 };
    expect = { 11 };
    assert(expect == s.maxSlidingWindow(nums, 2));

    nums = { 4,-2 };
    expect = { 4 };
    assert(expect == s.maxSlidingWindow(nums, 2));

    return 0;
}
