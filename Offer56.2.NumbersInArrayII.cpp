/**
 * @author Mr Dk.
 * @version 2021/02/14
 */

/*
    在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。
    请找出那个只出现一次的数字。

    示例 1：
        输入：nums = [3,4,3,3]
        输出：4

    示例 2：
        输入：nums = [9,1,7,9,7,9,7]
        输出：1

    限制：
        1 <= nums.length <= 10000
        1 <= nums[i] < 2^31

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    将所有数的二进制位按位累加，按位对 3 取模，剩下的二进制位就是只出现
    一次的数字。因为其它每个数字都出现了 3 次，所以二进制位对 3 取余之后
    结果一定为 0。
*/

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit_sum[32] = { 0 };
        for (size_t i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                bit_sum[j] += (nums[i] >> j) & 1;
            }
        }

        int single_number = 0;
        for (int i = 31; i >= 0; i--) {
            bit_sum[i] %= 3;
            single_number <<= 1;
            single_number |= bit_sum[i];
        }

        return single_number;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 3,4,3,3 };    
    assert(4 == s.singleNumber(nums));

    nums = { 9,1,7,9,7,9,7 };
    assert(1 == s.singleNumber(nums));

    return 0;
}
