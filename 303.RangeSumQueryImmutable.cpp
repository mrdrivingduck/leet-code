/**
 * @author Mr Dk.
 * @version 2021/03/01
 */

/*
    Given an integer array nums, find the sum of the elements between
    indices i and j (i ≤ j), inclusive.

    Implement the NumArray class:

    NumArray(int[] nums) Initializes the object with the integer array nums.
    int sumRange(int i, int j) Return the sum of the elements of the nums
    array in the range [i, j] inclusive (i.e., sum(nums[i], nums[i + 1],
    ... , nums[j])) 

    Example 1:
        Input
            ["NumArray", "sumRange", "sumRange", "sumRange"]
            [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
        Output
            [null, 1, -1, -3]

    Explanation
        NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
        numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
        numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
        numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))

    Constraints:
        0 <= nums.length <= 104
        -105 <= nums[i] <= 105
        0 <= i <= j < nums.length
        At most 104 calls will be made to sumRange.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/range-sum-query-immutable
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    维护一个当前位置之前所有元素累加和的数组。在需要查询某个区间的元素和时，用区间
    右端点的累加和减去区间左端点的累加和即可 (注意边界条件)。
 */

#include <cassert>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        sums.resize(nums.size() + 1);
        for (size_t i = 0; i < nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main()
{
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray n(nums);

    assert(1 == n.sumRange(0, 2));
    assert(-1 == n.sumRange(2, 5));
    assert(-3 == n.sumRange(0, 5));

    return 0;
}
