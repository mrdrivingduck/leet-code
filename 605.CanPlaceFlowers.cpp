/**
 * @author Mr Dk.
 * @version 2021/01/01 🎆
 */

/*
    You have a long flowerbed in which some of the plots are planted, and
    some are not. However, flowers cannot be planted in adjacent plots.

    Given an integer array flowerbed containing 0's and 1's, where 0 means
    empty and 1 means not empty, and an integer n, return if n new flowers
    can be planted in the flowerbed without violating the no-adjacent-flowers
    rule. 

    Example 1:
        Input: flowerbed = [1,0,0,0,1], n = 1
        Output: true

    Example 2:
        Input: flowerbed = [1,0,0,0,1], n = 2
        Output: false

    Constraints:
        1 <= flowerbed.length <= 2 * 104
        flowerbed[i] is 0 or 1.
        There are no two adjacent flowers in flowerbed.
        0 <= n <= flowerbed.length

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/can-place-flowers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    
 */

#include <cassert>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n) {
            return true;
        }
        
        int i = 0;
        while (i < (int) flowerbed.size()) {
            if (flowerbed[i]) {
                i += 2;
            } else {
                if ((i - 1 < 0 || !flowerbed[i - 1]) &&
                        (i + 1 >= (int) flowerbed.size() || !flowerbed[i + 1])) {
                    i += 2;
                    n--;
                    if (n == 0) {
                        return true;
                    }
                } else {
                    i++;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<int> flower_bed;
    
    flower_bed = { 1,0,0,0,1 };
    assert(true == s.canPlaceFlowers(flower_bed, 1));

    flower_bed = { 1,0,0,0,1 };
    assert(false == s.canPlaceFlowers(flower_bed, 2));

    flower_bed = { 1,0,1,0,1,0,1 };
    assert(true == s.canPlaceFlowers(flower_bed, 0));

    return 0;
}
