/**
 * @author Mr Dk.
 * @version 2021/01/09
 */

/*
    给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，
    ……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个
    函数，用来计算一个数字有多少种不同的翻译方法。

    示例 1:
        输入: 12258
        输出: 5
        解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

    提示：
        0 <= num < 231

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    使用递归，深度优先遍历搜索空间，直到搜索位置超出字符串长度。
*/

#include <cassert>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
private:
    int translate(string num, size_t start) {
        if (start >= num.size()) {
            return 1;
        }

        int result = 0;
        if (start < num.size()) {
            result += translate(num, start + 1);
        }
        if (start + 1 < num.size() &&
            (num[start] == '1' ||
                (num[start] == '2' && num[start + 1] < '6'))) {
            result += translate(num, start + 2);
        }

        return result;
    }

public:
    int translateNum(int num) {
        string num_str = std::to_string(num);
        return translate(num_str, 0);
    }
};

int main()
{
    Solution s;
    
    assert(5 == s.translateNum(12258));

    return 0;
}
