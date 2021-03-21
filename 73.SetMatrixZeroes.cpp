/**
 * @author Mr Dk.
 * @version 2021/03/21
 */

/*
    Given an m x n matrix. If an element is 0, set its entire row and
    column to 0. Do it in-place.

    Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best
    solution. Could you devise a constant space solution?

    Example 1:
        Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
        Output: [[1,0,1],[0,0,0],[1,0,1]]

    Example 2:
        Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
        Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

    Constraints:
        m == matrix.length
        n == matrix[0].length
        1 <= m, n <= 200
        -231 <= matrix[i][j] <= 231 - 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/set-matrix-zeroes
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    分别使用一个数组记录哪些行和哪些列需要被置空。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> _i(matrix.size(), false);
        vector<bool> _j(matrix[0].size(), false);

        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[i].size(); j++) {
                if (!matrix[i][j]) {
                    _i[i] = true;
                    _j[j] = true;
                }
            }
        }

        for (size_t i = 0; i < _i.size(); i++) {
            if (_i[i]) {
                matrix[i].assign(matrix[i].size(), 0);
            }
        }
        for (size_t j = 0; j < _j.size(); j++) {
            if (_j[j]) {
                for (size_t i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;
    vector<vector<int>> result;

    matrix = {
        { 1,1,1 },
        { 1,0,1 },
        { 1,1,1 }
    };
    result = {
        { 1,0,1 },
        { 0,0,0 },
        { 1,0,1 }
    };
    s.setZeroes(matrix);
    assert(result == matrix);

    matrix = {
        { 0,1,2,0 },
        { 3,4,5,2 },
        { 1,3,1,5 }
    };
    result = {
        { 0,0,0,0 },
        { 0,4,5,0 },
        { 0,3,1,0 }
    };
    s.setZeroes(matrix);
    assert(result == matrix);

    return 0;
}
