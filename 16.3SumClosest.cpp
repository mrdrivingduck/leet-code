/**
 * @author Mr Dk.
 * @version 2020/09/14
 */

/*
    Given an array nums of n integers and an integer target, find three
    integers in nums such that the sum is closest to target. Return the
    sum of the three integers. You may assume that each input would have
    exactly one solution. 

    Example 1:

    Input: nums = [-1,2,1,-4], target = 1
    Output: 2
    Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
     
    Constraints:

    3 <= nums.length <= 10^3
    -10^3 <= nums[i] <= 10^3
    -10^4 <= target <= 10^4

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/3sum-closest
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    双指针法，注意与上一道题的条件有所不同。
    在外层循环中不断迭代左边界，右边界不动；在内层循环中不断迭代双端边界，记录距离最近的 sum。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int distance = INT_MAX;
        int closest_sum = 0;
        int next;
        sort(nums.begin(), nums.end());

        unsigned int left_p = 0;
        while (left_p < nums.size()) {
            int left = left_p + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left_p] + nums[left] + nums[right];

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    if (target - sum < distance) {
                        distance = target - sum;
                        closest_sum = sum;
                    }
                    next = left + 1;
                    while (next < nums.size() && nums[next] == nums[left]) {
                        next++;
                    }
                    left = next;
                } else {
                    if (sum - target < distance) {
                        distance = sum - target;
                        closest_sum = sum;
                    }
                    next = right - 1;
                    while (next >= 0 && nums[next] == nums[right]) {
                        next--;
                    }
                    right = next;
                }
            }

            next = left_p + 1;
            while (next < nums.size() && nums[next] == nums[left_p]) {
                next++;
            }
            left_p = next;
        }

        return closest_sum;
    }
};

int main()
{
    // vector<int> list = { -1,2,1,-4 };
    // vector<int> list = { 0,0,0 };
    vector<int> list = { 1,1,1,1 };
    Solution s;
    int distance = s.threeSumClosest(list, 0);
    cout << distance << endl;

    return 0;
}