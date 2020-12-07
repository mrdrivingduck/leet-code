/**
 * @author Mr Dk.
 * @version 2020/12/07
 */

/*
    We have a two dimensional matrix A where each value is 0 or 1.

    A move consists of choosing any row or column, and toggling each value
    in that row or column: changing all 0s to 1s, and all 1s to 0s.

    After making any number of moves, every row of this matrix is
    interpreted as a binary number, and the score of the matrix is the sum
    of these numbers.

    Return the highest possible score.

    Example 1:
        Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
        Output: 39
        Explanation:
            Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
            0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    Note:
        1 <= A.length <= 20
        1 <= A[0].length <= 20
        A[i][j] is 0 or 1.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/score-after-flipping-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    首先通过行变换保证每一行都以 1 开头，然后通过列变换使每一列有尽可能多的 1。
    通过实现二进制位运算来加速。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        size_t line = A.size();
        size_t column = A[0].size();
        unsigned int *binary = new unsigned int[line];

        // convert to binary
        // make sure each number starts with bit-1
        for (size_t i = 0; i < line; i++) {
            binary[i] = 0;
            for (size_t j = 0; j < column; j++) {
                binary[i] <<= 1;
                binary[i] |= A[i][j];
            }
            if (!((binary[i] >> (column - 1)) & 1)) {
                binary[i] ^= (0xffffffff >> (32 - column));
            }
        }

        // make sure every column contains more bit-1
        unsigned int count;
        for (size_t i = 1; i < column; i++) {
            count = 0;
            for (size_t j = 0; j < line; j++) {
                if ((binary[j] >> (column - i - 1)) & 1) {
                    count++;
                }
            }
            if ((count << 1) < line) {
                for (size_t j = 0; j < line; j++) {
                    binary[j] ^= (1 << (column - i - 1));
                }
            }
        }

        // sum up
        count = 0;
        for (size_t i = 0; i < line; i++) {
            count += binary[i];
        }

        delete[] binary;
        return count;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> A = {
        { 0,0,1,1 },
        { 1,0,1,0 },
        { 1,1,0,0 }
    };
    
    cout << s.matrixScore(A) << endl;

    return 0;
}
