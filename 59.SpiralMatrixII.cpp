/**
 * @author Mr Dk.
 * @version 2021/03/16
 */

/*
    Given a positive integer n, generate an n x n matrix filled with
    elements from 1 to n2 in spiral order. 

    Example 1:
        Input: n = 3
        Output: [[1,2,3],[8,9,4],[7,6,5]]

    Example 2:
        Input: n = 1
        Output: [[1]]

    Constraints:
        1 <= n <= 20

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/spiral-matrix-ii
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int count = 1;
        int i = 0;
        int j = 0;
        bool next = true;
        while (next) {
            next = false;
            
            while (j < n && !visited[i][j]) {
                visited[i][j] = true;
                matrix[i][j] = count;
                count++;
                next = true;
                j++;
            }
            j--;
            i++;
            while (i < n && !visited[i][j]) {
                visited[i][j] = true;
                matrix[i][j] = count;
                count++;
                next = true;
                i++;
            }
            i--;
            j--;
            while (j >= 0 && !visited[i][j]) {
                visited[i][j] = true;
                matrix[i][j] = count;
                count++;
                next = true;
                j--;
            }
            j++;
            i--;
            while (i >= 0 && !visited[i][j]) {
                visited[i][j] = true;
                matrix[i][j] = count;
                count++;
                next = true;
                i--;
            }
            i++;
            j++;
        }

        return matrix;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;

    matrix = {
        { 1,2,3 },
        { 8,9,4 },
        { 7,6,5 }
    };
    assert(matrix == s.generateMatrix(3));

    // matrix = {
    //     { 1 }
    // };
    // assert(matrix == s.generateMatrix(1));

    return 0;
}
