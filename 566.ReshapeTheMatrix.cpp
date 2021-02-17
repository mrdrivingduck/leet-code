/**
 * @author Mr Dk.
 * @version 2021/02/17
 */

/*
    In MATLAB, there is a very useful function called 'reshape', which
    can reshape a matrix into a new one with different size but keep its
    original data.

    You're given a matrix represented by a two-dimensional array, and two
    positive integers r and c representing the row number and column number
    of the wanted reshaped matrix, respectively.

    The reshaped matrix need to be filled with all the elements of the
    original matrix in the same row-traversing order as they were.

    If the 'reshape' operation with given parameters is possible and legal,
    output the new reshaped matrix; Otherwise, output the original matrix.

    Example 1:
        Input: 
            nums = 
                [[1,2],
                [3,4]]
            r = 1, c = 4
        Output: 
            [[1,2,3,4]]
        Explanation:
            The row-traversing of nums is [1,2,3,4]. The new reshaped matrix
            is a 1 * 4 matrix, fill it row by row by using the previous list.

    Example 2:
        Input: 
            nums = 
                [[1,2],
                [3,4]]
            r = 2, c = 4
        Output: 
            [[1,2],
            [3,4]]
        Explanation:
            There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix.
            So output the original matrix.

    Note:
        The height and width of the given matrix is in range [1, 100].
        The given r and c are all positive.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reshape-the-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    首先判断一下矩阵的尺寸是否可以转换，如果可以，则转换。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int column = nums[0].size();
        if (r * c != row * column) {
            return nums;
        }

        vector<vector<int>> reshape(r, vector<int>(c));

        int _r = 0;
        int _c = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < nums[i].size(); j++) {
                reshape[_r][_c] = nums[i][j];
                _c++;
                if (_c >= c) {
                    _c = 0;
                    _r++;
                }
            }
        }

        return reshape;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> original;
    vector<vector<int>> result;
    
    original = { { 1,2 }, { 3,4 } };

    result = { { 1 }, { 2 }, { 3 }, { 4 } };
    assert(result == s.matrixReshape(original, 4, 1));

    result = { { 1,2,3,4 } };
    assert(result == s.matrixReshape(original, 1, 4));

    result = { { 1,2 }, { 3,4 } };
    assert(result == s.matrixReshape(original, 2, 4));

    return 0;
}
