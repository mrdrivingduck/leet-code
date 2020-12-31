/**
 * @author Mr Dk.
 * @version 2020/12/31
 */

/*
    Given a collection of intervals, find the minimum number of intervals
    you need to remove to make the rest of the intervals non-overlapping.

    Example 1:
        Input: [[1,2],[2,3],[3,4],[1,3]]
        Output: 1
        Explanation:
            [1,3] can be removed and the rest of intervals are non-overlapping.

    Example 2:
        Input: [[1,2],[1,2],[1,2]]
        Output: 2
        Explanation:
            You need to remove two [1,2] to make the rest of intervals
            non-overlapping.

    Example 3:
        Input: [[1,2],[2,3]]
        Output: 0
        Explanation:
            You don't need to remove any of the intervals since they're
            already non-overlapping.

    Note:
        You may assume the interval's end point is always bigger than its
        start point. Intervals like [1,2] and [2,3] have borders "touching"
        but they don't overlap each other.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/non-overlapping-intervals
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    把所有的区间按照右边界排序，如果上一个区间的右边界与下一个区间的左边界交叉，
    则抛弃下一个区间；否则，将右边界更新为下一个区间的右边界。

    2020 最后一题，再见~ 🎊
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

bool cmp(vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        
        std::sort(intervals.begin(), intervals.end(), cmp);

        int right_range = intervals[0][1];
        int remove = 0;
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < right_range) {
                remove++;
            } else {
                right_range = intervals[i][1];
            }
        }

        return remove;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals;

    intervals = { {1,2},{2,3},{3,4},{1,3} };
    assert(1 == s.eraseOverlapIntervals(intervals));

    intervals = { {1,2},{1,2},{1,2} };
    assert(2 == s.eraseOverlapIntervals(intervals));

    intervals = { {1,2},{2,3} };
    assert(0 == s.eraseOverlapIntervals(intervals));

    return 0;
}
