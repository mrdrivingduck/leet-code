/**
 * @author Mr Dk.
 * @version 2020.11.19
 */

/*
    Given an array nums, write a function to move all 0's to the end of
    it while maintaining the relative order of the non-zero elements.

    Example:
        Input: [0,1,0,3,12]
        Output: [1,3,12,0,0]

    Note:
        You must do this in-place without making a copy of the array.
        Minimize the total number of operations.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/move-zeroes
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    将 0 元素作为数组中的空位。使用两个指针，第一个指针用于指向当前的第一个空位，
    第二个指针遍历数组。如果遇上不是 0 的元素，就搬运到第一个空位置上，然后两个
    指针都后移，搬运的原位置也成为了空位。最终，将空位指针到数组尾部之间的所有
    位置都赋值为 0。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int empty = -1;
        int i = 0;
        while (i < (int) nums.size()) {
            if (empty == -1 && nums[i] == 0) {
                empty = i;
            } else if (empty != -1 && nums[i] != 0) {
                nums[empty] = nums[i];
                empty++;
            }
            i++;
        }
        if (empty != -1) {
            while (empty < (int) nums.size()) {
                nums[empty] = 0;
                empty++;
            }
        }
    }
};

int main() {
    Solution s;
    
    vector<int> seq = { 0,1,0,3,12 };
    s.moveZeroes(seq);
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    seq = { 1,1,1,0,3,0,0,6,5,3,1 };
    s.moveZeroes(seq);
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    seq = { 1,2,3,4,5 };
    s.moveZeroes(seq);
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    seq = { };
    s.moveZeroes(seq);
    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;

    return 0;
}