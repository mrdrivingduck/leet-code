/**
 * @author Mr Dk.
 * @version 2020.11.09
 */

/*
    We have a list of points on the plane. Find the K closest points to the
    origin (0, 0). (Here, the distance between two points on a plane is the
    Euclidean distance.)
    
    You may return the answer in any order.  The answer is guaranteed to be
    unique (except for the order that it is in.)

    Example 1:

    Input: points = [[1,3],[-2,2]], K = 1
    Output: [[-2,2]]

    Explanation: 
    The distance between (1, 3) and the origin is sqrt(10).
    The distance between (-2, 2) and the origin is sqrt(8).
    Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    We only want the closest K = 1 points from the origin, so the answer is
    just [[-2,2]].

    Example 2:

    Input: points = [[3,3],[5,-1],[-2,4]], K = 2
    Output: [[3,3],[-2,4]]
    (The answer [[-2,4],[3,3]] would also be accepted.)
     

    Note:

    1 <= K <= points.length <= 10000
    -10000 < points[i][0] < 10000
    -10000 < points[i][1] < 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/k-closest-points-to-origin
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    初级思路：利用 STL 的堆函数建堆，然后依次 pop 出堆顶元素。

    高级解法：利用 STL 的 nth_element() 函数，利用快速排序的思想，利用 pivot
    把数组切分为两份，然后依此类推，直接找到前 n 名的元素。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::size_t;

bool comp_small(vector<int> &a, vector<int> &b) {
    return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
}

bool comp_big(vector<int> &a, vector<int> &b) {
    return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
}

class Solution {
public:

    // vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    //     vector<vector<int>> pairs;
    //     pairs.reserve(K);

    //     make_heap(points.begin(), points.end(), comp_small);

    //     int i = 0;
    //     while (!points.empty() && i < K) {
    //         // cout << points[0][0] << " " << points[0][1] << endl;
    //         vector<int> top = { points[0][0], points[0][1] };
    //         pairs.push_back(top);
    //         pop_heap(points.begin(), points.end(), comp_small);
    //         points.pop_back();
    //         i++;
    //     }

    //     return pairs;
    // }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), comp_big);
        points.resize(K);

        return points;
    }
};

int main() {

    vector<int> pair1 = { 3,3 };
    vector<int> pair2 = { 5,-1 };
    vector<int> pair3 = { -2,4 };

    vector<vector<int>> pairs;
    pairs.push_back(pair1);
    pairs.push_back(pair2);
    pairs.push_back(pair3);

    Solution s;
    vector<vector<int>> res = s.kClosest(pairs, 2);

    return 0;
}
