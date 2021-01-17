/**
 * @author Mr Dk.
 * @version 2021/01/17
 */

/*
    You are given an array coordinates, coordinates[i] = [x, y], where
    [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

    Example 1:
        Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
        Output: true

    Example 2:
        Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
        Output: false

    Constraints:
        2 <= coordinates.length <= 1000
        coordinates[i].length == 2
        -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
        coordinates contains no duplicate point.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/check-if-it-is-a-straight-line
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    由于序列中最少会有两个点，就用这两个点计算出 x 轴和 y 轴的坐标差 (但不计算斜率)，
    之后依次计算每两个点之间的斜率，如果斜率不相等，则说明不在一条直线上。

    注意到这里不是通过除法来计算斜率，因为除法可能会导致结果不精确而无法比较。
    y1 / x1 = y2 / x2 可以等效为 x1 * y2 = x2 * y1，这样计算更为安全。
 */

#include <cassert>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int delta_x = coordinates[0][0] - coordinates[1][0];
        int delta_y = coordinates[0][1] - coordinates[1][1];

        for (size_t i = 2; i < coordinates.size(); i++) {
            int delta_x_ = coordinates[i][0] - coordinates[i - 1][0];
            int delta_y_ = coordinates[i][1] - coordinates[i - 1][1];

            if (delta_x * delta_y_ != delta_y * delta_x_) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> coordinates;

    coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    assert(true == s.checkStraightLine(coordinates));

    coordinates = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    assert(false == s.checkStraightLine(coordinates));

    return 0;
}
