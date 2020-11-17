/**
 * @author Mr Dk.
 * @version 2020.11.17
 */

/*
    We are given a matrix with R rows and C columns has cells with integer
    coordinates (r, c), where 0 <= r < R and 0 <= c < C.

    Additionally, we are given a cell in that matrix with coordinates (r0, c0).

    Return the coordinates of all cells in the matrix, sorted by their distance
    from (r0, c0) from smallest distance to largest distance.  Here, the distance
    between two cells (r1, c1) and (r2, c2) is the Manhattan distance,
    |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that satisfies
    this condition.)

    Example 1:
        Input: R = 1, C = 2, r0 = 0, c0 = 0
        Output: [[0,0],[0,1]]
        Explanation: The distances from (r0, c0) to other cells are: [0,1]

    Example 2:
        Input: R = 2, C = 2, r0 = 0, c0 = 1
        Output: [[0,1],[0,0],[1,1],[1,0]]
        Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
                        The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted
                        as correct.

    Example 3:
        Input: R = 2, C = 3, r0 = 1, c0 = 2
        Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
        Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
                        There are other answers that would also be accepted as correct,
                        such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
        
    Note:
        1 <= R <= 100
        1 <= C <= 100
        0 <= r0 < R
        0 <= c0 < C

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/matrix-cells-in-distance-order
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    直接通过循环构造出曼哈顿距离递增的序列。相同曼哈顿距离的点构成一个侧着的矩形。按四个方向遍历坐标，
    同时注意点的坐标不能跑到矩阵以外。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        result.reserve(R * C);

        size_t result_set_size = 0;
        vector<int> init = { r0, c0 };
        result.push_back(init);

        int distance = 1;

        // if there may be an increment in result, then loop...
        while (result_set_size != result.size()) {
            result_set_size = result.size();

            // start from top
            int x = r0 - distance;
            int y = c0;

            while (x != r0) {
                if (0 <= x && x < R && 0 <= y && y < C) {
                    vector<int> pair = { x, y };
                    result.push_back(pair);
                }
                x++;
                y--;
            }

            while (y != c0) {
                if (0 <= x && x < R && 0 <= y && y < C) {
                    vector<int> pair = { x, y };
                    result.push_back(pair);
                }
                x++;
                y++;
            }

            while (x != r0) {
                if (0 <= x && x < R && 0 <= y && y < C) {
                    vector<int> pair = { x, y };
                    result.push_back(pair);
                }
                x--;
                y++;
            }

            while (y != c0) {
                if (0 <= x && x < R && 0 <= y && y < C) {
                    vector<int> pair = { x, y };
                    result.push_back(pair);
                }
                x--;
                y--;
            }

            distance++;
        }

        return result;
    }
};

int main() {
    Solution s;
    
    vector<vector<int>> result = s.allCellsDistOrder(2, 2, 0, 1);
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << " " << result[i][1] << "]" << endl;
    }

    cout << endl;

    result = s.allCellsDistOrder(2, 3, 1, 2);
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << " " << result[i][1] << "]" << endl;
    }

    cout << endl;

    result = s.allCellsDistOrder(1, 1, 0, 0);
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << " " << result[i][1] << "]" << endl;
    }

    return 0;
}
