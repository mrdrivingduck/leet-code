/**
 * @author Mr Dk.
 * @version 2020/12/13 🕯
 */

/*
    Given an array of integers, find if the array contains any duplicates.

    Your function should return true if any value appears at least twice in
    the array, and it should return false if every element is distinct.

    Example 1:
        Input: [1,2,3,1]
        Output: true

    Example 2:
        Input: [1,2,3,4]
        Output: false

    Example 3:
        Input: [1,1,1,3,3,4,3,2,4,2]
        Output: true

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/contains-duplicate
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    简单题。简单查重，降低时间复杂度即可。

    注意，unordered_set 为哈希表实现。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (size_t i = 0; i < nums.size(); i++) {
            if (set.find(nums[i]) != set.end()) {
                return true;
            }
            set.insert(nums[i]);
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 1,2,3,1 };
    cout << s.containsDuplicate(nums) << endl;
    
    return 0;
}