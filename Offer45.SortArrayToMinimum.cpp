/**
 * @author Mr Dk.
 * @version 2020/12/03
 */

/*
    输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有
    数字中最小的一个。

    示例 1:
        输入: [10,2]
        输出: "102"

    示例 2:
        输入: [3,30,34,5,9]
        输出: "3033459"

    提示:
        0 < nums.length <= 100

    说明:
        输出结果可能非常大，所以你需要返回一个字符串而不是整数
        拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    自定义 STL 排序。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool compare(int &a, int &b) {
    string s1 = std::to_string(a);
    string s2 = std::to_string(b);

    return s1 + s2 < s2 + s1;
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), compare);
        string res;
        for (size_t i = 0; i < nums.size(); i++) {
            res.append(std::to_string(nums[i]));
        }

        return res;
    }
};


int main()
{
    Solution s;
    vector<int> nums;
    
    nums = { 3,30,34,5,9 };
    cout << s.minNumber(nums) << endl;

    nums = { 0,10,2 };
    cout << s.minNumber(nums) << endl;

    nums = { 824,938,1399,5607,6973,5703,9609,4398,8247 };
    // 1399 4398 5607 5703 6973 8247 824 938 9609
    cout << s.minNumber(nums) << endl;

    return 0;
}