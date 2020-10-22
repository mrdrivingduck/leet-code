/**
 * @author Mr Dk.
 * @version 2020/10/22
 */

/*
    地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子
    开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标
    的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
    但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

    示例 1：

    输入：m = 2, n = 3, k = 1
    输出：3

    示例 2：

    输入：m = 3, n = 1, k = 0
    输出：1

    提示：

    1 <= n,m <= 100
    0 <= k <= 20

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    广度优先遍历 + 获取数位的子函数。
*/

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> map(m, vector<bool>());
        for (int i = 0; i < m; i++) {
            map[i].resize(n, false);
        }

        queue<int> x_queue;
        queue<int> y_queue;
        x_queue.push(0);
        y_queue.push(0);
        map[0][0] = true;

        int sum = 0;

        while (!x_queue.empty()) {            
            int x = x_queue.front();
            int y = y_queue.front();
            x_queue.pop();
            y_queue.pop();
            sum++;

            if (x - 1 >= 0 && !map[x - 1][y] && digit_sum(x - 1) + digit_sum(y) <= k) {
                x_queue.push(x - 1);
                y_queue.push(y);
                map[x - 1][y] = true;
            }
            if (x + 1 < m && !map[x + 1][y] && digit_sum(x + 1) + digit_sum(y) <= k) {
                x_queue.push(x + 1);
                y_queue.push(y);
                map[x + 1][y] = true;
            }
            if (y - 1 >= 0 && !map[x][y - 1] && digit_sum(x) + digit_sum(y - 1) <= k) {
                x_queue.push(x);
                y_queue.push(y - 1);
                map[x][y - 1] = true;
            }
            if (y + 1 < n && !map[x][y + 1] && digit_sum(x) + digit_sum(y + 1) <= k) {
                x_queue.push(x);
                y_queue.push(y + 1);
                map[x][y + 1] = true;
            }
        }

        return sum;
    }

    int digit_sum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
};

int main()
{
    Solution s;
    // cout << s.digit_sum(106) << endl;
    // cout << s.digit_sum(0) << endl;
    // cout << s.digit_sum(10) << endl;
    // cout << s.digit_sum(1234) << endl;

    // cout << s.movingCount(2, 3, 1) << endl;
    // cout << s.movingCount(3, 1, 0) << endl;
    cout << s.movingCount(11, 8, 16) << endl;

    return 0;
}