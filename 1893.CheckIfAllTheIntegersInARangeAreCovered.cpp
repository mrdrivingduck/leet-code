/**
 * @author Mr Dk.
 * @version 2021/07/24
 */

/*
    You are given a 2D integer array ranges and two integers left and
    right. Each ranges[i] = [starti, endi] represents an inclusive
    interval between starti and endi.

    Return true if each integer in the inclusive range [left, right]
    is covered by at least one interval in ranges. Return false otherwise.

    An integer x is covered by an interval ranges[i] = [starti, endi]
    if starti <= x <= endi. 

    Example 1:
        Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
        Output: true
        Explanation:
            Every integer between 2 and 5 is covered:
                - 2 is covered by the first range.
                - 3 and 4 are covered by the second range.
                - 5 is covered by the third range.

    Example 2:
        Input: ranges = [[1,10],[10,20]], left = 21, right = 21
        Output: false
        Explanation:
            21 is not covered by any range.

    Constraints:
        1 <= ranges.length <= 50
        1 <= starti <= endi <= 50
        1 <= left <= right <= 50

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    将所有的范围按左右边界排序，然后用目标区间依次试探每个范围的左右边界。
*/

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

struct comp {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
};

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        std::sort(ranges.begin(), ranges.end(), comp());

        for (size_t i = 0; i < ranges.size(); i++) {
            if (ranges[i][0] > left) {
                return false;
            } else if (ranges[i][1] < left) {
                continue;
            } else {
                left = ranges[i][1] + 1;
                if (left > right) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ranges;

    ranges = { { 1,2 }, { 3,4 }, { 5,6 } };
    assert(s.isCovered(ranges, 2, 5));

    ranges = { { 1,10 }, { 10,20 } };
    assert(!s.isCovered(ranges, 21, 21));

    return 0;
}
