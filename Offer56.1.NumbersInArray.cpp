/**
 * @author Mr Dk.
 * @version 2021/01/30
 */

/*
    一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这
    两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。 

    示例 1：
        输入：nums = [4,1,4,6]
        输出：[1,6] 或 [6,1]

    示例 2：
        输入：nums = [1,2,10,4,1,4,3,3]
        输出：[2,10] 或 [10,2]

    限制：
        2 <= nums.length <= 10000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    数组中所有数字的异或结果为要找的数 A、B 的异或结果。该异或结果中为 1 的位就是
    A 和 B 的二进制表示中不同的位。将所有的数根据这一个位进行分组，那么：

    1. 相同的数肯定会被分到同一组中，异或后为 0
    2. A 和 B 肯定会被分到不同的组中

    那么分别对每一组进行异或，得到的数就是要找的 A、B。
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
    vector<int> singleNumbers(vector<int>& nums) {
        int xxor = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            xxor ^= nums[i];
        }

        int bit = 0;
        while (!(xxor & 1)) {
            xxor >>= 1;
            bit++;
        }

        int num1 = 0;
        int num2 = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] & (1 << bit)) {
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }

        return { num1, num2 };
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> unique;

    nums = { 4,1,4,6 };    
    unique = { 1,6 };
    assert(unique == s.singleNumbers(nums));

    nums = { 1,2,10,4,1,4,3,3 };
    unique = { 10, 2 };
    assert(unique == s.singleNumbers(nums));

    return 0;
}
