/**
 * @author Mr Dk.
 * @version 2021/02/25
 */

/*
    Given a 2D integer array matrix, return the transpose of matrix.

    The transpose of a matrix is the matrix flipped over its main diagonal,
    switching the matrix's row and column indices.

    Example 1:
        Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [[1,4,7],[2,5,8],[3,6,9]]

    Example 2:
        Input: matrix = [[1,2,3],[4,5,6]]
        Output: [[1,4],[2,5],[3,6]]

    Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 1000
        1 <= m * n <= 105
        -109 <= matrix[i][j] <= 109

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/transpose-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> t(matrix[0].size(), vector<int>(matrix.size()));

        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[i].size(); j++) {
                t[j][i] = matrix[i][j];
            }
        }

        return t;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> input;
    vector<vector<int>> output;

    input = { { 1,2,3 }, { 4,5,6 }, { 7,8,9 } };
    output = { { 1,4,7 }, { 2,5,8 }, { 3,6,9 } };
    assert(output == s.transpose(input));

    input = { { 1,2,3 }, { 4,5,6 } };
    output = { { 1,4 }, { 2,5 }, { 3,6 } };
    assert(output == s.transpose(input));

    return 0;
}
