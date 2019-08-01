/*
    Given an array of integers,
    return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution,
    and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/two-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    Solution

    Two-layer for iteration.
    Complexity - O(n^2)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        for (unsigned int i = 0; i < nums.size(); i++) {
            for (unsigned int j = i + 1; j < nums.size(); j++) {
                if (target == nums[i] + nums[j]) {
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    return vec;
                }
            }
        }
        return vec;
    }
};

int main() {
    // For testing
    vector <int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    Solution solution;
    vector<int> ano = solution.twoSum(nums, 9);
    for (unsigned int i = 0; i < ano.size(); i++) {
        cout << ano[i] << endl;
    }

    return 0;
}
