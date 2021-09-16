/**
 * @author Mr Dk.
 * @version 2021/09/16
 */

/*
    Given a list of 24-hour clock time points in "HH:MM" format, return
    the minimum minutes difference between any two time-points in the list.

    Example 1:
        Input: timePoints = ["23:59","00:00"]
        Output: 1

    Example 2:
        Input: timePoints = ["00:00","23:59","00:00"]
        Output: 0

    Constraints:
        2 <= timePoints <= 2 * 104
        timePoints[i] is in the format "HH:MM".

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/minimum-time-difference
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    将所有的时间转换为分钟，然后进行排序，选择相邻元素中最小的差值。
    注意最后一个元素和第一个元组之间的差值。可以通过在最后一个元素后面
    添加一个第一个元素的副本 (累加 24h) 来实现。
 */

#include <cassert>
#include <climits>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times(timePoints.size());

        for (size_t i = 0; i < timePoints.size(); i++) {
            int hour   = std::stoi(timePoints[i].substr(0, 2));
            int minute = std::stoi(timePoints[i].substr(3, 2));

            times[i] = hour * 60 + minute;
        }

        std::sort(times.begin(), times.end());
        times.push_back(times.front() + 24 * 60);

        int min = INT32_MAX;
        for (size_t i = 1; i < times.size(); i++) {
            min = std::min(min, times[i] - times[i - 1]);
            if (min == 0) {
                return min;
            }
        }

        return min;
    }
};

int main()
{
    Solution s;
    vector<string> points;

    points = { "23:59","00:00" };
    assert(1 == s.findMinDifference(points));

    points = { "00:00","23:59","00:00" };
    assert(0 == s.findMinDifference(points));

    return 0;
}
