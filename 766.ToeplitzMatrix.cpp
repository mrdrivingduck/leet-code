/**
 * @author Mr Dk.
 * @version 2021/02/22
 */

/*
    Given an m x n matrix, return true if the matrix is Toeplitz.
    Otherwise, return false.

    A matrix is Toeplitz if every diagonal from top-left to bottom-right
    has the same elements. 

    Example 1:
        Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
        Output: true
        Explanation: In the above grid, the diagonals are:
            "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
            In each diagonal all elements are the same, so the answer is True.

    Example 2:
        Input: matrix = [[1,2],[2,2]]
        Output: false
        Explanation:
            The diagonal "[1, 2]" has different elements. 

    Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 20
        0 <= matrix[i][j] <= 99

    Follow up:
        What if the matrix is stored on disk, and the memory is limited such
        that you can only load at most one row of the matrix into the memory
        at once?
        What if the matrix is so large that you can only load up a partial
        row into the memory at once?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/toeplitz-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    依次比较除第一个元素外的所有对角元。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) {
            return true;
        }
        for (size_t i = 0; i < matrix.size() - 1; i++) {
            size_t j = 0;
            while (j < matrix[i].size() - 1) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) {
                    return false;
                }
                j++;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;

    matrix = { { 1,2,3,4 }, { 5,1,2,3 }, { 9,5,1,2 } };
    assert(true == s.isToeplitzMatrix(matrix));

    matrix = { { 1,2 }, { 2,2 } };
    assert(false == s.isToeplitzMatrix(matrix));

    return 0;
}
