/**
 * @author Mr Dk.
 * @version 2021/08/07
 */

/*
    Given an array nums with n objects colored red, white, or blue, sort them
    in-place so that objects of the same color are adjacent, with the colors in
    the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and
    blue, respectively.

    You must solve this problem without using the library's sort function. 

    Example 1:
        Input: nums = [2,0,2,1,1,0]
        Output: [0,0,1,1,2,2]

    Example 2:
        Input: nums = [2,0,1]
        Output: [0,1,2]

    Example 3:
        Input: nums = [0]
        Output: [0]

    Example 4:
        Input: nums = [1]
        Output: [1]

    Constraints:
        n == nums.length
        1 <= n <= 300
        nums[i] is 0, 1, or 2.

    Follow up:
        Could you come up with a one-pass algorithm using only constant
        extra space?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sort-colors
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    分三个区，前面的是 0 区，后面的是 2 区。遍历数组，不断把 0 和 2 交换到最前面
    和最后面去，剩下的就全是 1 了。
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
    void sortColors(vector<int>& nums) {
        int front = 0;
        int back = nums.size();
        int i = 0;

        while (i < back) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[front++]);
                if (i < front) {
                    i = front;
                }
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[--back]);
            } else {
                i++;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> input;
    vector<int> output;

    input = { 2,0,2,1,1,0 };
    output = { 0,0,1,1,2,2 };
    s.sortColors(input);
    assert(output == input);

    input = { 2,0,1 };
    output = { 0,1,2 };
    s.sortColors(input);
    assert(output == input);

    input = { 0 };
    output = { 0 };
    s.sortColors(input);
    assert(output == input);
    
    input = { 1 };
    output = { 1 };
    s.sortColors(input);
    assert(output == input);

    return 0;
}
