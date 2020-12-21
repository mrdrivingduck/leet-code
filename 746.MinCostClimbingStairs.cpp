/**
 * @author Mr Dk.
 * @version 2020/12/21
 */

/*
    On a staircase, the i-th step has some non-negative cost cost[i]
    assigned (0 indexed).

    Once you pay the cost, you can either climb one or two steps. You
    need to find minimum cost to reach the top of the floor, and you
    can either start from the step with index 0, or the step with index 1.

    Example 1:
        Input: cost = [10, 15, 20]
        Output: 15
        Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

    Example 2:
        Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
        Output: 6
        Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

    Note:
        cost will have a length in the range [2, 1000].
        Every cost[i] will be an integer in the range [0, 999].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    动态规划。刚开始的两个阶梯是不需要体力的，登上下一节阶梯耗费的体力是 min{登上前一级
    阶梯之前所耗的体力 + 前一级阶梯需要耗费的体力, 登上前两级阶梯之前所耗的体力 + 前两级
    阶梯需要耗费的体力}。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> min_cost(cost.size() + 1);
        min_cost[0] = 0;
        min_cost[1] = 0;

        for (size_t i = 2; i < min_cost.size(); i++) {
            int step1 = min_cost[i - 1] + cost[i - 1];
            int step2 = min_cost[i - 2] + cost[i - 2];
            min_cost[i] = (step1 < step2) ? step1 : step2;
        }

        return min_cost[min_cost.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> cost;
    
    cost = { 10, 15, 20 };
    assert(15 == s.minCostClimbingStairs(cost));

    cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    assert(6 == s.minCostClimbingStairs(cost));

    return 0;
}
