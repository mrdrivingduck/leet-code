/**
 * @author Mr Dk.
 * @version 2021/02/20
 */

/*
    Given a non-empty array of non-negative integers nums, the degree of
    this array is defined as the maximum frequency of any one of its
    elements.

    Your task is to find the smallest possible length of a (contiguous)
    subarray of nums, that has the same degree as nums. 

    Example 1:
        Input: nums = [1,2,2,3,1]
        Output: 2
        Explanation: 
            The input array has a degree of 2 because both elements 1
            and 2 appear twice.
            Of the subarrays that have the same degree:
                [1, 2, 2, 3, 1],
                [1, 2, 2, 3],
                [2, 2, 3, 1],
                [1, 2, 2],
                [2, 2, 3],
                [2, 2]
            The shortest length is 2. So return 2.

    Example 2:
        Input: nums = [1,2,2,3,1,4,2]
        Output: 6
        Explanation: 
            The degree is 3 because the element 2 is repeated 3 times.
            So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

    Constraints:
        nums.length will be between 1 and 50,000.
        nums[i] will be an integer between 0 and 49,999.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/degree-of-an-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    通过 hash table 计算出数组的度，然后使用滑动窗口统计具有该度的
    最小子数组长度。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0;
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator iter;

        for (size_t i = 0; i < nums.size(); i++) {
            iter = map.find(nums[i]);
            if (iter == map.end()) {
                iter = map.insert(std::make_pair(nums[i], 1)).first;
            } else {
                iter->second++;
            }

            if (iter->second > degree) {
                degree = iter->second;
            }
        }

        map.clear();

        int left = 0;
        int right = 0;
        int min_len = nums.size();
        
        while (right < (int) nums.size()) {
            iter = map.find(nums[right]);
            if (iter == map.end()) {
                iter = map.insert(std::make_pair(nums[right], 1)).first;
            } else {
                iter->second++;
            }

            while (iter->second >= degree) {
                min_len = std::min(min_len, right - left + 1);
                map[nums[left]]--;
                left++;
            }

            right++;
        }

        return min_len;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = { 1,2,2,3,1 };
    assert(2 == s.findShortestSubArray(nums));

    nums = { 1,2,2,3,1,4,2 };
    assert(6 == s.findShortestSubArray(nums));

    return 0;
}
