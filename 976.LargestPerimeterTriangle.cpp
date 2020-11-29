/**
 * @author Mr Dk.
 * @version 2020/11/29
 */

/*
    Given an array A of positive lengths, return the largest perimeter of a
    triangle with non-zero area, formed from 3 of these lengths.

    If it is impossible to form any triangle of non-zero area, return 0.

    Example 1:
        Input: [2,1,2]
        Output: 5

    Example 2:
        Input: [1,2,1]
        Output: 0

    Example 3:
        Input: [3,2,3,4]
        Output: 10

    Example 4:
        Input: [3,6,2,3]
        Output: 8

    Note:
        3 <= A.length <= 10000
        1 <= A[i] <= 10^6

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/largest-perimeter-triangle
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    首先对数组排序，然后先取最长的一条作为侯选边，然后找两条次长的边，看看是否
    满足三角形任意两边之和大于第三边，如果不满足，那么更短的边也无法满足。那么
    再接着选择次长的最长边。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::size_t;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        std::sort(A.begin(), A.end());

        for (int i = A.size() - 1; i >= 2; i--) {
            if (A[i] < A[i - 1] + A[i - 2]) {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> edges;

    edges = { 2,1,2 };
    cout << s.largestPerimeter(edges) << endl;

    edges = { 1,2,1 };
    cout << s.largestPerimeter(edges) << endl;

    edges = { 3,2,3,4 };
    cout << s.largestPerimeter(edges) << endl;

    edges = { 3,6,2,3 };
    cout << s.largestPerimeter(edges) << endl;

    return 0;
}
