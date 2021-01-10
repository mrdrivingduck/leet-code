/**
 * @author Mr Dk.
 * @version 2021/01/10
 */

/*
    You are given a sorted unique integer array nums.

    Return the smallest sorted list of ranges that cover all the numbers
    in the array exactly. That is, each element of nums is covered by
    exactly one of the ranges, and there is no integer x such that x is
    in one of the ranges but not in nums.

    Each range [a,b] in the list should be output as:
        "a->b" if a != b
        "a" if a == b

    Example 1:
        Input: nums = [0,1,2,4,5,7]
        Output: ["0->2","4->5","7"]
        Explanation: The ranges are:
            [0,2] --> "0->2"
            [4,5] --> "4->5"
            [7,7] --> "7"

    Example 2:
        Input: nums = [0,2,3,4,6,8,9]
        Output: ["0","2->4","6","8->9"]
        Explanation: The ranges are:
            [0,0] --> "0"
            [2,4] --> "2->4"
            [6,6] --> "6"
            [8,9] --> "8->9"

    Example 3:
        Input: nums = []
        Output: []

    Example 4:
        Input: nums = [-1]
        Output: ["-1"]

    Example 5:
        Input: nums = [0]
        Output: ["0"]

    Constraints:
        0 <= nums.length <= 20
        -2^31 <= nums[i] <= 2^31 - 1
        All the values of nums are unique.
        nums is sorted in ascending order.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/summary-ranges
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    题目含义为找到所有连续相邻数字组成的所有区间。

    在判断条件的实现上，已经不止一次遇到了这样的问题：同样的逻辑，要实现为
    不会发生溢出的形式 - 要使计算的中间结果绝对值尽可能小，处于表示范围以内。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }

        size_t pre = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > 1 + nums[i - 1]) {
                string s;
                s.append(std::to_string(nums[pre]));
                if (pre != i - 1) {
                    s.append("->");
                    s.append(std::to_string(nums[i - 1]));
                }
                result.push_back(s);

                pre = i;
            }
        }

        string s;
        s.append(std::to_string(nums[pre]));
        if (pre != nums.size() - 1) {
            s.append("->");
            s.append(std::to_string(nums[nums.size() - 1]));
        }
        result.push_back(s);

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<string> result;

    nums = { 0,1,2,4,5,7 };
    result = { "0->2", "4->5", "7" };
    assert(result == s.summaryRanges(nums));

    nums = { 0,2,3,4,6,8,9 };
    result = { "0", "2->4", "6", "8->9" };
    assert(result == s.summaryRanges(nums));

    nums = {  };
    result = {  };
    assert(result == s.summaryRanges(nums));

    nums = { -1 };
    result = { "-1" };
    assert(result == s.summaryRanges(nums));

    nums = { 0 };
    result = { "0" };
    assert(result == s.summaryRanges(nums));
    
    return 0;
}
