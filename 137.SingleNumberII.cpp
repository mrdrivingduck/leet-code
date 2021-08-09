/**
 * @author Mr Dk.
 * @version 2021/08/09
 */

/*
    Given an integer array nums where every element appears three times
    except for one, which appears exactly once. Find the single element
    and return it.

    You must implement a solution with a linear runtime complexity and
    use only constant extra space. 

    Example 1:
        Input: nums = [2,2,3,2]
        Output: 3

    Example 2:
        Input: nums = [0,1,0,1,0,1,99]
        Output: 99

    Constraints:
        1 <= nums.length <= 3 * 104
        -231 <= nums[i] <= 231 - 1
        Each element in nums appears exactly three times except for one
        element which appears once.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/single-number-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    用一个长度为 32 的数组累加所有数字中各个位上 1 的个数，然后对 3 取余，
    剩下的数字就是唯一出现的数字的各个位。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = { 0 };

        for (unsigned int i = 0; i < 32; i++) {
            for (int num : nums) {
                if (num & (1 << i)) {
                    bits[i]++;
                }
            }

            bits[i] %= 3;
        }

        int result = 0;
        for (int i = 0; i < 32; i++) {
            result |= (bits[i] << i);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 2,2,3,2 };
    assert(3 == s.singleNumber(nums));

    nums = { 0,1,0,1,0,1,99 };
    assert(99 == s.singleNumber(nums));

    return 0;
}
