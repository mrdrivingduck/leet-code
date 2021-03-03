/**
 * @author Mr Dk.
 * @version 2021/03/03
 */

/*
    找出数组中重复的数字。

    在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字
    是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中
    任意一个重复的数字。

    示例 1：
        输入：
            [2, 3, 1, 0, 2, 5, 3]
        输出：2 或 3 

    限制：
        2 <= n <= 100000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    原地置换与下标不相等的元素，如果元素对应的下标中已有对应元素，则说明
    当前元素重复。
*/

#include <cassert>

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < (int) nums.size(); i++) {
            if (i != nums[i]) {
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                } else {
                    int swap = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = swap;
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 2, 3, 1, 0, 2, 5, 3 };
    assert(2 == s.findRepeatNumber(nums));

    return 0;
}
