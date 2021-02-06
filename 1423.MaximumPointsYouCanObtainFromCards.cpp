/**
 * @author Mr Dk.
 * @version 2021/02/06
 */

/*
    There are several cards arranged in a row, and each card has an
    associated number of points The points are given in the integer
    array cardPoints.

    In one step, you can take one card from the beginning or from the
    end of the row. You have to take exactly k cards.

    Your score is the sum of the points of the cards you have taken.

    Given the integer array cardPoints and the integer k, return the
    maximum score you can obtain. 

    Example 1:
        Input: cardPoints = [1,2,3,4,5,6,1], k = 3
        Output: 12
        Explanation:
            After the first step, your score will always be 1. However,
            choosing the rightmost card first will maximize your total
            score. The optimal strategy is to take the three cards on
            the right, giving a final score of 1 + 6 + 5 = 12.

    Example 2:
        Input: cardPoints = [2,2,2], k = 2
        Output: 4
        Explanation:
            Regardless of which two cards you take, your score will
            always be 4.

    Example 3:
        Input: cardPoints = [9,7,7,9,7,7,9], k = 7
        Output: 55
        Explanation:
            You have to take all the cards. Your score is the sum of
            points of all cards.

    Example 4:
        Input: cardPoints = [1,1000,1], k = 1
        Output: 1
        Explanation:
            You cannot take the card in the middle. Your best score is 1. 

    Example 5:
        Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
        Output: 202

    Constraints:
        1 <= cardPoints.length <= 10^5
        1 <= cardPoints[i] <= 10^4
        1 <= k <= cardPoints.length

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    反向思维。由于操作结束后，剩下的卡牌一定是连续的 n - k 张，因此只需要
    找出 n - k 张连续卡牌中，点数之和最小的区间即可。所有卡牌的点数之和
    减去点数之和最小的连续区间，剩下的就是拿走的最大点数之和。
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
    int maxScore(vector<int>& cardPoints, int k) {
        int window_len = cardPoints.size() - k;
        int min = INT32_MAX;
        int window_sum = 0;
        int sum = 0;

        int i = 0;
        while (i < (int) cardPoints.size()) {
            window_sum += cardPoints[i];
            sum += cardPoints[i];

            i++;

            if (i >= window_len && window_len > 0) {
                min = std::min(min, window_sum);
                window_sum -= cardPoints[i - window_len];
            }
        }

        if (min == INT32_MAX) {
            min = 0;
        }
        
        return sum - min;
    }
};

int main()
{
    Solution s;
    vector<int> cards;

    cards = { 1,2,3,4,5,6,1 };
    assert(12 == s.maxScore(cards, 3));

    cards = { 2,2,2 };
    assert(4 == s.maxScore(cards, 2));

    cards = { 9,7,7,9,7,7,9 };
    assert(55 == s.maxScore(cards, 7));

    cards = { 1,1000,1 };
    assert(1 == s.maxScore(cards, 1));

    cards = { 1,79,80,1,1,1,200,1 };
    assert(202 == s.maxScore(cards, 3));

    return 0;
}
