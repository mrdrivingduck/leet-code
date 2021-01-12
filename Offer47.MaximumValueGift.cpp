/**
 * @author Mr Dk.
 * @version 2021/01/12
 */

/*
    在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
    你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘
    的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

    示例 1:
        输入: 
            [
              [1,3,1],
              [1,5,1],
              [4,2,1]
            ]
        输出: 12
        解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

    提示：
        0 < grid.length <= 200
        0 < grid[0].length <= 200

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    动态规划。选择上面位置和左边位置的较大值与当前位置礼物的价值累加。
*/

#include <cassert>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for (size_t i = 1; i < grid[0].size(); i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (size_t i = 1; i < grid.size(); i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (size_t i = 1; i < grid.size(); i++) {
            for (size_t j = 1; j < grid[0].size(); j++) {
                if (grid[i - 1][j] > grid[i][j - 1]) {
                    grid[i][j] += grid[i - 1][j];
                } else {
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }

        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid;

    grid = { { 1,3,1 }, { 1,5,1 }, { 4,2,1 } };
    assert(12 == s.maxValue(grid));

    return 0;
}
