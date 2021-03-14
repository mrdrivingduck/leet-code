/**
 * @author Mr Dk.
 * @version 2021/03/14
 */

/*
    Given a non-negative integer n, count all numbers with unique digits,
    x, where 0 ≤ x < 10n.

    Example:
        Input: 2
        Output: 91 
        Explanation:
            The answer should be the total numbers in the range of 0 ≤ x < 100, 
            excluding 11,22,33,44,55,66,77,88,99

    Constraints:
        0 <= n <= 8

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/count-numbers-with-unique-digits
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    更长一位的不同数字个数可以由更短一位的不同数字个数递推得出 (可选的数字越来越少)。
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
    int countNumbersWithUniqueDigits(int n) {
        vector<int> unique(9, 1);
        unique[1] = 9;
        unique[2] = 81;

        for (int i = 3; i <= n; i++) {
            unique[i] = unique[i - 1] * (11 - i);
        }
        
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += unique[i];
        }

        return sum;
    }
};

int main()
{
    Solution s;
    
    assert(91 == s.countNumbersWithUniqueDigits(2));
    assert(10 == s.countNumbersWithUniqueDigits(1));
    assert(1 == s.countNumbersWithUniqueDigits(0));

    return 0;
}
