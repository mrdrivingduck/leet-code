/**
 * @author Mr Dk.
 * @version 2021/03/03
 */

/*
    在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从
    上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，
    判断数组中是否含有该整数。 

    示例:
        现有矩阵 matrix 如下：
        [
            [1,   4,  7, 11, 15],
            [2,   5,  8, 12, 19],
            [3,   6,  9, 16, 22],
            [10, 13, 14, 17, 24],
            [18, 21, 23, 26, 30]
        ]
        给定 target = 5，返回 true。
        给定 target = 20，返回 false。

    限制：
        0 <= n <= 1000
        0 <= m <= 1000

    注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    从数组右上角开始搜素：
        如果当前元素大于目标值，则向左边一列搜素 (因为当前列的后面元素肯定大于目标值)
        如果当前元素小于目标值，则向下面一行搜索 (因为右边一列已经不可能了)
*/

#include <cassert>

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) {
            return false;
        }

        int i = 0;
        int j = matrix[0].size() - 1;

        while (i < (int) matrix.size() && j < (int) matrix[i].size()) {
            if (matrix[i][j] > target) {
                j--;
                if (j < 0) {
                    return false;
                }
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;

    matrix = {
        { 1,   4,  7, 11, 15 },
        { 2,   5,  8, 12, 19 },
        { 3,   6,  9, 16, 22 },
        { 10, 13, 14, 17, 24 },
        { 18, 21, 23, 26, 30 }
    };
    assert(s.findNumberIn2DArray(matrix, 5));
    assert(!s.findNumberIn2DArray(matrix, 20));

    return 0;
}
