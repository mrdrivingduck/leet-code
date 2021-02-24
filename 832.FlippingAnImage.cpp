/**
 * @author Mr Dk.
 * @version 2021/02/24
 */

/*
    Given a binary matrix A, we want to flip the image horizontally, then
    invert it, and return the resulting image.

    To flip an image horizontally means that each row of the image is
    reversed.  For example, flipping [1, 1, 0] horizontally results in
    [0, 1, 1].

    To invert an image means that each 0 is replaced by 1, and each 1 is
    replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

    Example 1:
        Input: [[1,1,0],[1,0,1],[0,0,0]]
        Output: [[1,0,0],[0,1,0],[1,1,1]]
        Explanation:
            First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
            Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

    Example 2:
        Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
        Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
        Explanation:
            First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
            Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

    Notes:
        1 <= A.length = A[0].length <= 20
        0 <= A[i][j] <= 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/flipping-an-image
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    先逆置再翻转。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

int flip(int &i) {
    return !i;
}

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (size_t i = 0; i < A.size(); i++) {
            std::reverse(A[i].begin(), A[i].end());
            std::transform(A[i].begin(), A[i].end(), A[i].begin(), flip);
        }

        return A;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> input;
    vector<vector<int>> output;

    input = {{1,1,0},{1,0,1},{0,0,0}};
    output = {{1,0,0},{0,1,0},{1,1,1}};
    assert(output == s.flipAndInvertImage(input));

    input = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    output = {{1,1,0,0},{0,1,1,0},{0,0,0,1},{1,0,1,0}};
    assert(output == s.flipAndInvertImage(input));

    return 0;
}
