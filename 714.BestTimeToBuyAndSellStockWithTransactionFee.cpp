/**
 * @author Mr Dk.
 * @version 2020/12/18
 */

/*
    Your are given an array of integers prices, for which the i-th
    element is the price of a given stock on day i; and a non-negative
    integer fee representing a transaction fee.

    You may complete as many transactions as you like, but you need to
    pay the transaction fee for each transaction. You may not buy more
    than 1 share of a stock at a time (ie. you must sell the stock share
    before you buy again.)

    Return the maximum profit you can make.

    Example 1:
        Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
        Output: 8
        Explanation: The maximum profit can be achieved by:
            Buying at prices[0] = 1
            Selling at prices[3] = 8
            Buying at prices[4] = 4
            Selling at prices[5] = 9
            The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

    Note:
        0 < prices.length <= 50000.
        0 < prices[i] < 50000.
        0 <= fee < 50000.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    记录目前持有股票的成本。接下来的日子里，如果持有的股票上涨，且利润超过了手续费，
    那么就累加扣去利润的手续费，然后将目前持有股票的成本提升到这一天的价格减去手续费 - 
    因为接下来如果再上涨将不用计算手续费了；如果持有的股票下跌，那么将股票成本设置为
    这一天的价格。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int delta;
        int min = prices[0];

        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else if ((delta = prices[i] - min - fee) > 0) {
                profit += delta;
                min = prices[i] - fee;
            }
        }

        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices;

    prices = { 1,3,2,8,4,9 };
    cout << s.maxProfit(prices, 2) << endl;

    prices = { 4,5,2,4,3,3,1,2,5,4 };
    cout << s.maxProfit(prices, 1) << endl;
    
    prices = { 1, 3, 2, 8, 4, 9 };
    cout << s.maxProfit(prices, 2) << endl;
    cout << s.maxProfit(prices, 0) << endl;

    prices = { 1,3,7,5,10,3 };
    cout << s.maxProfit(prices, 3) << endl;

    return 0;
}
