/**
 * @author Mr Dk.
 * @version 2021/03/02
 */

/*
    Given a 2D matrix matrix, find the sum of the elements inside the
    rectangle defined by its upper left corner (row1, col1) and lower
    right corner (row2, col2).

    The above rectangle (with the red border) is defined by (row1, col1)
    = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

    Example:
        Given matrix = [
            [3, 0, 1, 4, 2],
            [5, 6, 3, 2, 1],
            [1, 2, 0, 1, 5],
            [4, 1, 0, 1, 7],
            [1, 0, 3, 0, 5]
        ]

        sumRegion(2, 1, 4, 3) -> 8
        sumRegion(1, 1, 2, 2) -> 11
        sumRegion(1, 2, 2, 4) -> 12

    Note:
        You may assume that the matrix does not change.
        There are many calls to sumRegion function.
        You may assume that row1 ≤ row2 and col1 ≤ col2.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    为每一行维护好前缀和，以便之后能够快速查找。
 */

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class NumMatrix {
private:
    vector<vector<int>> line_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix.size(); i++) {
            vector<int> line(matrix[i].size() + 1, 0);
            for (size_t j = 0; j < matrix[i].size(); j++) {
                line[j + 1] = line[j] + matrix[i][j];
            }
            line_sum.push_back(line);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += line_sum[i][col2 + 1] - line_sum[i][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    vector<vector<int>> matrix = {
        { 3, 0, 1, 4, 2 },
        { 5, 6, 3, 2, 1 },
        { 1, 2, 0, 1, 5 },
        { 4, 1, 0, 1, 7 },
        { 1, 0, 3, 0, 5 }
    };
    
    NumMatrix n(matrix);
    assert(8 == n.sumRegion(2, 1, 4, 3));
    assert(11 == n.sumRegion(1, 1, 2, 2));
    assert(12 == n.sumRegion(1, 2, 2, 4));

    return 0;
}
