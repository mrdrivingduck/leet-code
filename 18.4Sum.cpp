/**
 * @author Mr DK.
 * @version 2020/10/13
 */

/*
    Given an array nums of n integers and an integer target, are there
    elements a, b, c, and d in nums such that a + b + c + d = target?
    Find all unique quadruplets in the array which gives the sum of target.

    Note:

    The solution set must not contain duplicate quadruplets.

    Example:

    Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

    A solution set is:

    [
        [-1,  0, 0, 1],
        [-2, -1, 1, 2],
        [-2,  0, 0, 2]
    ]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/4sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    基于 3Sum，外面多套了一层循环。先用两层循环定死两个位置，然后剩下的区间用双指针
    从两端开始迭代，并进行 early exit。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> arr_list;

        if (nums.size() < 4) {
            return arr_list;
        }
        sort(nums.begin(), nums.end());

        int cur1 = 0;
        while (cur1 < nums.size() - 1) {
            int cur2 = cur1 + 1;

            while (cur2 < nums.size()) {
                int left = cur2 + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int sum = nums[cur1] + nums[cur2] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> res = { nums[cur1], nums[cur2], nums[left], nums[right] };
                        cout << nums[cur1] << " " << nums[cur2] << " " << nums[left] << " " << nums[right] << endl;
                        arr_list.push_back(res);
                        left = find_next(nums, left, false);
                        right = find_next(nums, right, true);
                    } else if (sum > target) {
                        right = find_next(nums, right, true);
                    } else {
                        left = find_next(nums, left, false);
                    }
                }

                cur2 = find_next(nums, cur2, false);
            }

            cur1 = find_next(nums, cur1, false);
        }

        return arr_list;
    }

private:
    int find_next(vector<int>& nums, int current, bool left) {
        int i = left ? current - 1 : current + 1;
        if (i < 0 || i >= nums.size()) {
            return i;
        }
        while (i >= 0 && i < nums.size() && nums[i] == nums[current]) {
            if (left) {
                i--;
            } else {
                i++;
            }
        }

        return i;
    }
};


int main()
{
    vector<int> list = { 1, 0, -1, 0, -2, 2 };
    Solution s;
    s.fourSum(list, 0);

    return 0;
}