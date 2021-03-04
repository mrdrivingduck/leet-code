/**
 * @author Mr Dk.
 * @version 2021/03/04
 */

/*
    You are given an array prices where prices[i] is the price of a given
    stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one
    stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If
    you cannot achieve any profit, return 0. 

    Example 1:
        Input: prices = [7,1,5,3,6,4]
        Output: 5
        Explanation:
            Buy on day 2 (price = 1) and sell on day 5 (price = 6),
            profit = 6-1 = 5.
            Note that buying on day 2 and selling on day 1 is not allowed
            because you must buy before you sell.

    Example 2:
        Input: prices = [7,6,4,3,1]
        Output: 0
        Explanation:
            In this case, no transactions are done and the max profit = 0.

    Constraints:
        1 <= prices.length <= 105
        0 <= prices[i] <= 104

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    在每个位置上，记录到目前为止遇到的最低股票价格。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                max = std::max(max, prices[i] - prices[i - 1]);
            }

            prices[i] = std::min(prices[i], prices[i - 1]);
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> prices;

    prices = { 7,1,5,3,6,4 };
    assert(5 == s.maxProfit(prices));

    prices = { 7,6,4,3,1 };
    assert(0 == s.maxProfit(prices));
    
    return 0;
}
