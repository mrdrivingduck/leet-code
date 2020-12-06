/**
 * @author Mr Dk.
 * @version 2020/12/06
 */

/*
    Given a non-negative integer numRows, generate the first numRows of
    Pascal's triangle.In Pascal's triangle, each number is the sum of
    the two numbers directly above it.

    Example:
        Input: 5
        Output:
        [
              [1],
             [1,1],
            [1,2,1],
           [1,3,3,1],
          [1,4,6,4,1]
        ]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/pascals-triangle
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    杨辉三角，过于简单了。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> lines;
        lines.reserve(numRows);
        if (numRows < 1) {
            return lines;
        }

        vector<int> line = { 1 };
        lines.push_back(line);
        for (size_t i = 1; i < (size_t) numRows; i++) {
            line.resize(0);
            line.push_back(1);
            for (size_t j = 0; j < lines[lines.size() - 1].size() - 1; j++) {
                line.push_back(lines[lines.size() - 1][j] + lines[lines.size() - 1][j + 1]);
            }
            line.push_back(1);
            lines.push_back(line);
        }

        return lines;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> tri;

    tri = s.generate(5);
    for (size_t i = 0; i < tri.size(); i++) {
        for (size_t j = 0; j < tri[i].size(); j++) {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}