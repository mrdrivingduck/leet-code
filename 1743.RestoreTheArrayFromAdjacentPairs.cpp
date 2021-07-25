/**
 * @author Mr Dk.
 * @version 2021/07/25
 */

/*
    There is an integer array nums that consists of n unique elements,
    but you have forgotten it. However, you do remember every pair of
    adjacent elements in nums.

    You are given a 2D integer array adjacentPairs of size n - 1 where
    each adjacentPairs[i] = [ui, vi] indicates that the elements ui and
    vi are adjacent in nums.

    It is guaranteed that every adjacent pair of elements nums[i] and
    nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]]
    or [nums[i+1], nums[i]]. The pairs can appear in any order.

    Return the original array nums. If there are multiple solutions,
    return any of them.

    Example 1:
        Input:
            adjacentPairs = [[2,1],[3,4],[3,2]]
        Output:
            [1,2,3,4]
        Explanation:
            This array has all its adjacent pairs in adjacentPairs.
            Notice that adjacentPairs[i] may not be in left-to-right order.

    Example 2:
        Input:
            adjacentPairs = [[4,-2],[1,4],[-3,1]]
        Output:
            [-2,4,1,-3]
        Explanation:
            There can be negative numbers.
            Another solution is [-3,1,4,-2], which would also be accepted.

    Example 3:
        Input:
            adjacentPairs = [[100000,-100000]]
        Output:
            [100000,-100000]

    Constraints:
        nums.length == n
        adjacentPairs.length == n - 1
        adjacentPairs[i].length == 2
        2 <= n <= 105
        -105 <= nums[i], ui, vi <= 105
        There exists some nums that has adjacentPairs as its pairs.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    遍历 pairs，找到只出现过一次的元素，该元素一定是序列的两端。然后通过
    这个元素依次找出与其相邻的元素。为了快速查找一个元素的相邻元素，可以
    遍历一次 pairs，构造出一个 hash table，降低时间复杂度。
*/

#include <cassert>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::unordered_set;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacents;
        unordered_map<int, vector<int>>::iterator iter;
        unordered_set<int> dup;

        for (size_t i = 0; i < adjacentPairs.size(); i++) {
            int e1 = adjacentPairs[i][0];
            int e2 = adjacentPairs[i][1];
            
            // build a hash table to store adjacents of each element
            if ((iter = adjacents.find(e1)) != adjacents.end()) {
                iter->second.push_back(e2);
            } else {
                adjacents.insert(std::make_pair(e1, vector<int>(1, e2)));
            }

            if ((iter = adjacents.find(e2)) != adjacents.end()) {
                iter->second.push_back(e1);
            } else {
                adjacents.insert(std::make_pair(e2, vector<int>(1, e1)));
            }

            // to find the end point element
            if (dup.find(e1) != dup.end()) {
                dup.erase(e1);
            } else {
                dup.insert(e1);
            }
            if (dup.find(e2) != dup.end()) {
                dup.erase(e2);
            } else {
                dup.insert(e2);
            }
        }

        // end point element as current one
        int element = *(dup.begin());

        vector<int> result(1, element);
        dup.clear();
        dup.insert(element);

        for (size_t i = 1; i < adjacentPairs.size() + 1; i++) {
            // to find adjacent element of current element
            // meanwhile, avoid using duplicated element
            iter = adjacents.find(element);
            if (dup.find(iter->second[0]) != dup.end()) {
                element = iter->second[1];
            } else {
                element = iter->second[0];
            }
            result.push_back(element);
            dup.insert(element);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> pairs;
    vector<int> output;

    pairs = {
        {-3,-9},{-5,3},{2,-9},{6,-3},{6,1},{5,3},{8,5},{-5,1},{7,2}
    };
    output = { 7,2,-9,-3,6,1,-5,3,5,8 };
    assert(output == s.restoreArray(pairs));

    pairs = { { 2,1 }, { 3,4 }, { 3,2 } };
    output = { 4,3,2,1 };
    assert(output == s.restoreArray(pairs));

    pairs = { { 4,-2 }, { 1,4 }, { -3,1 } };
    output = { -3,1,4,-2 };
    assert(output == s.restoreArray(pairs));

    pairs = { { 10000,-10000 } };
    output = { -10000,10000 };
    assert(output == s.restoreArray(pairs));

    return 0;
}
