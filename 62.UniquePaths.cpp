/**
 * @author Mr Dk.
 * @version 2020/12/09
 */

/*
    A robot is located at the top-left corner of a m x n grid (marked
    'Start' in the diagram below).

    The robot can only move either down or right at any point in time.
    The robot is trying to reach the bottom-right corner of the grid
    (marked 'Finish' in the diagram below).

    How many possible unique paths are there?

    Example 1:
        Input: m = 3, n = 7
        Output: 28

    Example 2:
        Input: m = 3, n = 2
        Output: 3
        Explanation:
            From the top-left corner, there are a total of 3 ways to
            reach the bottom-right corner:
                1. Right -> Down -> Down
                2. Down -> Down -> Right
                3. Down -> Right -> Down

    Example 3:
        Input: m = 7, n = 3
        Output: 28

    Example 4:
        Input: m = 3, n = 3
        Output: 6

    Constraints:
        1 <= m, n <= 100
        It's guaranteed that the answer will be less than or equal
        to 2 * 109.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/unique-paths
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    排列组合。由 m - 1 次向下的步骤和 n - 1 次向右的步骤组合而成。也就是说，
    要在 m + n - 2 个步骤中，选择 m - 1 或 n - 1 (结果相同) 个向下的操作
    或向右的操作，也就是 C(m + n - 2, m - 1) 或 C(m + n - 2, n - 1)。
 */

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }

        // (m + n - 2) * (m + n - 3) * ... * n
        // ------------------------------------
        // (m - 1) * (m - 2) * ... * 1

        long long result = 1;

        for (int i = n; i <= m + n - 2; i++) {
            result = result * i / (i - n + 1);
        }

        return result;
    }
};

int main()
{
    Solution s;

    cout << s.uniquePaths(3, 7) << endl;
    cout << s.uniquePaths(3, 2) << endl;
    cout << s.uniquePaths(7, 3) << endl;
    cout << s.uniquePaths(3, 3) << endl;

    return 0;
}
