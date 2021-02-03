/**
 * @author Mr Dk.
 * @version 2021/02/03
 */

/*
    Median is the middle value in an ordered integer list. If the size
    of the list is even, there is no middle value. So the median is the
    mean of the two middle value.

    Examples:
    [2,3,4] , the median is 3

    [2,3], the median is (2 + 3) / 2 = 2.5

    Given an array nums, there is a sliding window of size k which is moving
    from the very left of the array to the very right. You can only see the k
    numbers in the window. Each time the sliding window moves right by one
    position. Your job is to output the median array for each window in the
    original array.

    For example,
    Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

    Window position                Median
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       1
    1 [3  -1  -3] 5  3  6  7       -1
    1  3 [-1  -3  5] 3  6  7       -1
    1  3  -1 [-3  5  3] 6  7       3
    1  3  -1  -3 [5  3  6] 7       5
    1  3  -1  -3  5 [3  6  7]      6

    Therefore, return the median sliding window as [1,-1,-1,3,5,6].

    Note:
    You may assume k is always valid, ie: k is always smaller than input
    array's size for non-empty array.
    Answers within 10^-5 of the actual value will be accepted as correct.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sliding-window-median
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    本想用两个对顶堆实现的，后发现题目要求滑动窗口，而堆没有快速删除元素
    的性质。因而使用两个 multiset 维护滑动窗口，保证第一个 set 的大小永远
    大于等于第二个 set，并且元素保持有序。每次根据第一个 set 的最后一个元素
    和第二个 set 的第一个元素，就可以快速计算中位数。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::multiset;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> smaller;
        multiset<int> bigger;
        vector<double> medians;

        for (size_t i = 0; i <= nums.size(); i++) {
            if (i < (size_t) k) {
                bigger.insert(nums[i]);
            } else {
                while (smaller.size() < bigger.size()) {
                    int swap = *bigger.begin();
                    bigger.erase(bigger.begin());
                    smaller.insert(swap);
                }
                while (smaller.size() > bigger.size() + 1) {
                    int swap = *(--smaller.end());
                    smaller.erase(--smaller.end());
                    bigger.insert(swap);
                }

                if (smaller.size() > bigger.size()) {
                    medians.push_back(*(--smaller.end()));
                } else {
                    medians.push_back(((double) *(--smaller.end()) + *bigger.begin()) / 2);
                }

                if (i == nums.size()) {
                    break;
                }

                multiset<int>::iterator iter;
                iter = smaller.find(nums[i - k]);
                if (iter != smaller.end()) {
                    smaller.erase(iter);
                } else {
                    iter = bigger.find(nums[i - k]);
                    bigger.erase(iter);
                }

                if (
                    (!bigger.empty() && nums[i] <= *bigger.begin()) ||
                    (!smaller.empty() && nums[i] < *(--smaller.end()))
                ) {
                    smaller.insert(nums[i]);
                } else {
                    bigger.insert(nums[i]);
                }
            }
        }

        // for (size_t i = 0; i < medians.size(); i++) {
        //     cout << medians[i] << " ";
        // }
        // cout << endl;

        return medians;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<double> medians;

    nums = { 1,2,3,4,2,3,1,4,2 };
    medians = { 2,3,3,3,2,3,2 };
    assert(medians == s.medianSlidingWindow(nums, 3));
    
    nums = { 1,3,-1,-3,5,3,6,7 };
    medians = { 1,-1,-1,3,5,6 };
    assert(medians == s.medianSlidingWindow(nums, 3));

    return 0;
}
