/**
 * @author Mr Dk.
 * @version 2021/02/23
 */

/*
    Today, the bookstore owner has a store open for customers.length
    minutes.  Every minute, some number of customers (customers[i])
    enter the store, and all those customers leave after the end of
    that minute.

    On some minutes, the bookstore owner is grumpy.  If the bookstore
    owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise
    grumpy[i] = 0.  When the bookstore owner is grumpy, the customers
    of that minute are not satisfied, otherwise they are satisfied.

    The bookstore owner knows a secret technique to keep themselves not
    grumpy for X minutes straight, but can only use it once.

    Return the maximum number of customers that can be satisfied
    throughout the day. 

    Example 1:
        Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
        Output: 16
        Explanation:
            The bookstore owner keeps themselves not grumpy for the last
            3 minutes. 
            The maximum number of customers that can be satisfied = 1 + 1 + 1
            + 1 + 7 + 5 = 16.

    Note:
        1 <= X <= customers.length == grumpy.length <= 20000
        0 <= customers[i] <= 1000
        0 <= grumpy[i] <= 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/grumpy-bookstore-owner
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    通过一个滑动窗口维护可以挽回的最大顾客数量。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int left = 0;
        int right = 0;

        int window_forgive = 0;
        int satisfied = 0;
        while (right < X) {
            if (grumpy[right]) {
                window_forgive += customers[right];
            } else {
                satisfied += customers[right];
            }
            right++;
        }

        int max_forgive = window_forgive;
        while (right < (int) customers.size()) {
            if (grumpy[right]) {
                window_forgive += customers[right];
            } else {
                satisfied += customers[right];
            }

            if (grumpy[left]) {
                window_forgive -= customers[left];
            }
            left++;

            max_forgive = std::max(max_forgive, window_forgive);

            right++;
        }

        return satisfied + max_forgive;
    }
};

int main()
{
    Solution s;
    vector<int> customers;
    vector<int> grumpy;

    customers = { 1,0,1,2,1,1,7,5 };
    grumpy = { 0,1,0,1,0,1,0,1 };
    assert(16 == s.maxSatisfied(customers, grumpy, 3));

    return 0;
}
