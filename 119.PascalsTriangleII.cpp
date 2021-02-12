/**
 * @author Mr Dk.
 * @version 2021/02/12
 */

/*
    Given an integer rowIndex, return the rowIndexth row of the Pascal's
    triangle.

    Notice that the row index starts from 0.

    In Pascal's triangle, each number is the sum of the two numbers directly
    above it.

    Follow up:
        Could you optimize your algorithm to use only O(k) extra space?

    Example 1:
        Input: rowIndex = 3
        Output: [1,3,3,1]

    Example 2:
        Input: rowIndex = 0
        Output: [1]

    Example 3:
        Input: rowIndex = 1
        Output: [1,1]

    Constraints:
        0 <= rowIndex <= 33

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/pascals-triangle-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    重用空间版本的杨辉三角。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        if (rowIndex < 1) {
            return row;
        }

        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                row[j] += row[j - 1];
            }
        }

        // for (size_t i = 0; i < row.size(); i++) {
        //     cout << row[i] << " ";
        // }
        // cout << endl;

        return row;
    }
};

int main()
{
    Solution s;
    vector<int> row;

    row = { 1,3,3,1 };
    assert(row == s.getRow(3));

    row = { 1 };
    assert(row == s.getRow(0));

    row = { 1,1 };
    assert(row == s.getRow(1));
    
    return 0;
}
