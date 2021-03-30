/**
 * @author Mr Dk.
 * @version 2021/03/30
 */

/*
    Write an efficient algorithm that searches for a value in an m x n
    matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of
    the previous row.

    Example 1:
        Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
        Output: true

    Example 2:
        Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
        Output: false

    Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 100
        -104 <= matrix[i][j], target <= 104

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/search-a-2d-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    首先根据矩阵第一列的数组进行二分查找，确定元素所在的行；然后再对
    该行进行二分查找。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] > target) {
                right = mid - 1;
            } else if (matrix[mid][0] < target) {
                if (mid + 1 < (int) matrix.size() && matrix[mid + 1][0] > target) {
                    left = mid;
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                return true;
            }
        }

        return std::binary_search(matrix[left].begin(), matrix[left].end(), target);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;

    matrix = {
        { 1 },
        { 3 },
    };
    assert(true == s.searchMatrix(matrix, 3));

    matrix = {
        { 1,3,5,7 },
        { 10,11,16,20 },
        { 23,30,34,60 }
    };
    assert(true == s.searchMatrix(matrix, 3));
    assert(false == s.searchMatrix(matrix, 13));

    return 0;
}
