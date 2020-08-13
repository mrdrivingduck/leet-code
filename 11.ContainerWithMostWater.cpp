/**
 * @author Mr Dk.
 * @version 2020/08/13
 */

/*
    Given n non-negative integers a1, a2, ..., an , where each represents
    a point at coordinate (i, ai). n vertical lines are drawn such that
    the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
    which together with x-axis forms a container, such that the container
    contains the most water.

    Note: You may not slant the container and n is at least 2.

    The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
    In this case, the max area of water (blue section) the container can
    contain is 49.

    Example:

    Input: [1,8,6,2,5,4,8,3,7]
    Output: 49

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/container-with-most-water
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    双指针法。两个指针分别指向头和尾，同时向中间移动，重合时结束。

    1. 当两个指针向中间移动时，由于宽度减少，只有高度增加的才有机会使面积增加。
    2. 面积由两边的最小高度决定，因此每次应当固定高度大的一端，向中间移动高度较小的一端 (探索有没有增加最小高度的可能)。

    使两个指针中的高度大的固定，另一个向中间移动，移动过程中只计算高度增加垂直轴与另一指针所在垂直轴的面积。
    当移动端的高度超过固定端时，将原来的移动端固定，开始移动另一端。
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max = (height[left] < height[right]) ?
            (height[left] * (right - left)) :
            (height[right] * (right - left));
        int current = 0;

        // 左右指针重合时结束
        while (left < right) {

            // 左指针高度小，固定右指针
            while (height[left] <= height[right]) {
                left++;
                if (left == right) {
                    return max;
                }
                // 左指针高度增加，计算可能的新的最大面积
                if (height[left] > height[left - 1]) {
                    current = (height[left] < height[right]) ?
                                (height[left] * (right - left)) :
                                (height[right] * (right - left));
                    max = (current > max) ? current : max;
                }
            }

            // 右指针高度小，固定左指针
            while (height[left] >= height[right]) {
                right--;
                if (left == right) {
                    return max;
                }
                // 右指针高度增加，计算可能的新的最大面积
                if (height[right] > height[right + 1]) {
                    current = (height[left] < height[right]) ?
                                (height[left] * (right - left)) :
                                (height[right] * (right - left));
                    max = (current > max) ? current : max;
                }
            }
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> list = { 1,8,6,2,5,4,8,3,7 };
    cout << s.maxArea(list) << endl; // 49
    list = { 1,2,4,3 };
    cout << s.maxArea(list) << endl; // 4

    return 0;
}