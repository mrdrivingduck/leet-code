/**
 * @author Mr Dk.
 * @version 2021/03/15
 */

/*
    Given two arrays nums1 and nums2.

    Return the maximum dot product between non-empty subsequences of
    nums1 and nums2 with the same length.

    A subsequence of a array is a new array which is formed from the
    original array by deleting some (can be none) of the characters without
    disturbing the relative positions of the remaining characters.
    (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not). 

    Example 1:
        Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
        Output: 18
        Explanation:
            Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
            Their dot product is (2*3 + (-2)*(-6)) = 18.

    Example 2:
        Input: nums1 = [3,-2], nums2 = [2,-6,7]
        Output: 21
        Explanation:
            Take subsequence [3] from nums1 and subsequence [7] from nums2.
            Their dot product is (3*7) = 21.

    Example 3:
        Input: nums1 = [-1,-1], nums2 = [1,1]
        Output: -1
        Explanation:
            Take subsequence [-1] from nums1 and subsequence [1] from nums2.
            Their dot product is -1.

    Constraints:
        1 <= nums1.length, nums2.length <= 500
        -1000 <= nums1[i], nums2[i] <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/max-dot-product-of-two-subsequences
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    动态规划，首先将二维数组中的每个位置初始化为元素的乘积。然后遍历每个位置，
    每个位置的选择有：
        1. 不使用当前位置的元素计算点积，使用之前的累加点积：[i - 1][j] 或 [i][j - 1] 中的结果
        2. 使用当前位置的元素计算点积，使用之前的累加点积：[i - 1][j - 1] + [i][j]
        3. 如果之前的累加点积为负，那么直接抛弃之前累加的点积，使用当前位置的点积作为新开始：[i][j]
    使用以上三者的最大值即可。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> product(nums1.size(), vector<int>(nums2.size()));
        for (size_t i = 0; i < nums1.size(); i++) {
            for (size_t j = 0; j < nums2.size(); j++) {
                product[i][j] = nums1[i] * nums2[j];
            }
        }

        for (size_t i = 0; i < nums1.size(); i++) {
            for (size_t j = 0; j < nums2.size(); j++) {
                if (i > 0 && j > 0) {
                    product[i][j] = std::max(product[i][j], product[i - 1][j - 1] + product[i][j]);
                }
                if (i > 0) {
                    product[i][j] = std::max(product[i][j], product[i - 1][j]);
                }
                if (j > 0) {
                    product[i][j] = std::max(product[i][j], product[i][j - 1]);
                }
            }
        }

        // for (size_t i = 0; i < nums1.size(); i++) {
        //     for (size_t j = 0; j < nums2.size(); j++) {
        //         cout << product[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return product[nums1.size() - 1][nums2.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> nums1;
    vector<int> nums2;

    nums1 = { -5,3,-5,-3,1 };
    nums2 = { -2,4,2,5,-5 };
    assert(50 == s.maxDotProduct(nums1, nums2));

    // nums1 = { 5,-4,-3 };
    // nums2 = { -4,-3,0,-4,2 };
    // assert(28 == s.maxDotProduct(nums1, nums2));

    // nums1 = { 2,1,-2,5 };
    // nums2 = { 3,0,-6 };
    // assert(18 == s.maxDotProduct(nums1, nums2));

    // nums1 = { 3,-2 };
    // nums2 = { 2,-6,7 };
    // assert(21 == s.maxDotProduct(nums1, nums2));

    // nums1 = { -1,-1 };
    // nums2 = { 1,1 };
    // assert(-1 == s.maxDotProduct(nums1, nums2));

    return 0;
}
