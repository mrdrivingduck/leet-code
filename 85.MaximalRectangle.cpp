/**
 * @author Mr Dk.
 * @version 2020/12/26
 */

/*
    Given a rows x cols binary matrix filled with 0's and 1's, find the
    largest rectangle containing only 1's and return its area.

    Example 1:
        Input: matrix = [
            ["1","0","1","0","0"],
            ["1","0","1","1","1"],
            ["1","1","1","1","1"],
            ["1","0","0","1","0"]
        ]
        Output: 6
        Explanation: The maximal rectangle is shown in the above picture.

    Example 2:
        Input: matrix = []
        Output: 0

    Example 3:
        Input: matrix = [["0"]]
        Output: 0

    Example 4:
        Input: matrix = [["1"]]
        Output: 1

    Example 5:
        Input: matrix = [["0","0"]]
        Output: 0

    Constraints:
        rows == matrix.length
        cols == matrix.length
        0 <= row, cols <= 200
        matrix[i][j] is '0' or '1'.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximal-rectangle
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    遍历一遍矩阵，保存每行每个元素左边有多少个连续的 1。
    以每个非零元素作为矩阵的右下角，从垂直方向向上遍历 (条件：垂直方向上元素不为 0)，
    并更新矩阵的宽度 (每行左边连续 1 数量的较小值) 和高度 (每次 + 1)，同时计算最大面积。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        vector<vector<int>> horizontal(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    horizontal[i][j] = 0;
                } else {
                    // number of continuous 1 on the left (including itself)
                    horizontal[i][j] = j > 0 ? horizontal[i][j - 1] + 1 : 1;
                }
            }
        }

        int max = 0;
        int range;

        for (int i = 0; i < (int) horizontal.size(); i++) {
            for (int j = 0; j < (int) horizontal[0].size(); j++) {
                for (int height = 1, width = horizontal[i][j];
                        i + 1 - height >= 0 /* height does not exceed matrix top */ &&
                        horizontal[i + 1 - height][j]; /* element is not 0 */
                        height++) {

                    // width should be the minimum continuous 1 number
                    // of every line in rectangle.
                    width = horizontal[i + 1 - height][j] < width ?
                            horizontal[i + 1 - height][j] :
                            width;

                    if ((range = width * height) > max) {
                        max = range;
                    }
                }
            }
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix;
    
    matrix = {
        { '1','0','1','0','0' },
        { '1','0','1','1','1' },
        { '1','1','1','1','1' },
        { '1','0','0','1','0' }
    };
    assert(6 == s.maximalRectangle(matrix));

    matrix = {};
    assert(0 == s.maximalRectangle(matrix));

    matrix = { { '0' } };
    assert(0 == s.maximalRectangle(matrix));

    matrix = { { '1' } };
    assert(1 == s.maximalRectangle(matrix));

    matrix = { { '0','0' } };
    assert(0 == s.maximalRectangle(matrix));

    return 0;
}
