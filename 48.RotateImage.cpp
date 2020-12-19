/**
 * @author Mr Dk.
 * @version 2020/12/19
 */

/*
    You are given an n x n 2D matrix representing an image, rotate the image
    by 90 degrees (clockwise).

    You have to rotate the image in-place, which means you have to modify the
    input 2D matrix directly. DO NOT allocate another 2D matrix and do the
    rotation. 

    Example 1:
        Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [[7,4,1],[8,5,2],[9,6,3]]

    Example 2:
        Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
        Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

    Example 3:
        Input: matrix = [[1]]
        Output: [[1]]

    Example 4:
        Input: matrix = [[1,2],[3,4]]
        Output: [[3,1],[4,2]]

    Constraints:
        matrix.length == n
        matrix[i].length == n
        1 <= n <= 20
        -1000 <= matrix[i][j] <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/rotate-image
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    先将矩阵沿对角线做对称变换，然后将每一行 reverse。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = i + 1; j < matrix[i].size(); j++) {
                int swap = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = swap;
            }
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    Solution s;
    
    vector<int> line1 = { 1,2,3 };
    vector<int> line2 = { 4,5,6 };
    vector<int> line3 = { 7,8,9 };
    vector<vector<int>> matrix = { line1, line2, line3 };

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    s.rotate(matrix);

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
