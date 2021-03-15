/**
 * @author Mr Dk.
 * @version 2021/03/15
 */

/*
    Given an m x n matrix, return all elements of the matrix in spiral order.

    Example 1:
        Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [1,2,3,6,9,8,7,4,5]

    Example 2:
        Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
        Output: [1,2,3,4,8,12,11,10,9,5,6,7]

    Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 10
        -100 <= matrix[i][j] <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/spiral-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    维护一个结点是否被访问过的数组，与矩阵大小相同。在遍历时，在触碰矩阵
    边界或碰到已经访问过的结点后，立刻改变方向。当没有任何方向可以改变
    时，遍历结束。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<int> order;
        order.reserve(matrix[0].size() * matrix.size());

        int i = 0;
        int j = 0;
        bool next = true;
        while (next) {
            next = false;
            while (j < (int) matrix[0].size() && !visited[i][j]) {
                visited[i][j] = true;
                order.push_back(matrix[i][j]);
                j++;
                next = true;

            }
            j--;
            i++;
            while (i < (int) matrix.size() && !visited[i][j]) {
                visited[i][j] = true;
                order.push_back(matrix[i][j]);
                i++;
                next = true;
            }
            i--;
            j--;
            while (j >= 0 && !visited[i][j]) {
                visited[i][j] = true;
                order.push_back(matrix[i][j]);
                j--;
                next = true;
            }
            j++;
            i--;
            while (i >= 0 && !visited[i][j]) {
                visited[i][j] = true;
                order.push_back(matrix[i][j]);
                i--;
                next = true;
            }
            i++;
            j++;
        }

        return order;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;
    vector<int> spiral_order;

    matrix = {
        { 1,2,3 },
        { 4,5,6 },
        { 7,8,9 }
    };
    spiral_order = { 1,2,3,6,9,8,7,4,5 };
    assert(spiral_order == s.spiralOrder(matrix));

    return 0;
}
