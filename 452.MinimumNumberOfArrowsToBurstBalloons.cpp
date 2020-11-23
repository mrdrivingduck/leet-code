/**
 * @author Mr Dk.
 * @version 2020.11.23
 */

/*
    There are some spherical balloons spread in two-dimensional space.
    For each balloon, provided input is the start and end coordinates
    of the horizontal diameter. Since it's horizontal, y-coordinates
    don't matter, and hence the x-coordinates of start and end of the
    diameter suffice. The start is always smaller than the end.

    An arrow can be shot up exactly vertically from different points
    along the x-axis. A balloon with xstart and xend bursts by an arrow
    shot at x if xstart ≤ x ≤ xend. There is no limit to the number of
    arrows that can be shot. An arrow once shot keeps traveling up
    infinitely.

    Given an array points where points[i] = [xstart, xend], return the
    minimum number of arrows that must be shot to burst all balloons.

    Example 1:
        Input: points = [[10,16],[2,8],[1,6],[7,12]]
        Output: 2
        Explanation: One way is to shoot one arrow for example at x = 6
            (bursting the balloons [2,8] and [1,6]) and another arrow at
            x = 11 (bursting the other two balloons).

    Example 2:
        Input: points = [[1,2],[3,4],[5,6],[7,8]]
        Output: 4

    Example 3:
        Input: points = [[1,2],[2,3],[3,4],[4,5]]
        Output: 2

    Example 4:
        Input: points = [[1,2]]
        Output: 1

    Example 5:
        Input: points = [[2,3],[2,3]]
        Output: 1

    Constraints:
        0 <= points.length <= 104
        points[i].length == 2
        -231 <= xstart < xend <= 231 - 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    贪心算法，将所有气球按右边界排序后可以发现，每次至少肯定需要一根箭射到第一个气球的右边界上，
    才能保证这个气球最终一定被射爆。之后，射爆每一个气球时，向后判断所有可以同时被射爆的气球，
    判断方式是左边界小于当前射箭位置。下一轮的迭代，直接从下一个没有交集的气球开始，以节省时间
    复杂度。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort according to right border
        sort(points.begin(), points.end(), cmp);

        int shoot = 0;

        size_t i = 0, j;
        while (i < points.size()) {
            shoot++; // shoot one balloon

            for (j = i + 1; j < points.size(); j++) {
                if (points[j][0] > points[i][1]) {
                    // the first balloon that cannot
                    // been shoot at the same time
                    i = j; // directly jump to shoot this balloon
                    break;
                }
            }

            // no more balloon
            if (j == points.size()) {
                break;
            }
        }

        return shoot;
    }
};

int main() {
    Solution s;
    vector<vector<int>> input;
    
    input = { { 10,16 }, { 2,8 }, { 1,6 }, { 7,12 } };
    cout << s.findMinArrowShots(input) << endl;
    input = { { 1,2 }, { 3,4 }, { 5,6 }, { 7,8 } };
    cout << s.findMinArrowShots(input) << endl;
    input = { { 1,2 }, { 2,3 }, { 3,4 }, { 4,5 } };
    cout << s.findMinArrowShots(input) << endl;
    input = { { 1,2 } };
    cout << s.findMinArrowShots(input) << endl;
    input = { { 2,3 }, { 2,3 } };
    cout << s.findMinArrowShots(input) << endl;

    return 0;
}
