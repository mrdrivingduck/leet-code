/**
 * @author Mr Dk.
 * @version 2021/03/03
 */

/*
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct
    ways can you climb to the top? 

    Example 1:
        Input: n = 2
        Output: 2
        Explanation:
            There are two ways to climb to the top.
            1. 1 step + 1 step
            2. 2 steps

    Example 2:
        Input: n = 3
        Output: 3
        Explanation:
            There are three ways to climb to the top.
            1. 1 step + 1 step + 1 step
            2. 1 step + 2 steps
            3. 2 steps + 1 step

    Constraints:
        1 <= n <= 45

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/climbing-stairs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    
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
    int numWays(int n) {
        vector<int> arr(n + 1, 0);
        arr[0] = 1;
        if (n > 0) {
            arr[1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000007;
        }
        
        return arr[n];
    }
};

int main()
{
    Solution s;

    assert(2 == s.numWays(2));

    assert(21 == s.numWays(7));

    assert(1 == s.numWays(0));

    return 0;
}
