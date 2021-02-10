/**
 * @author Mr Dk.
 * @version 2021/02/10
 */

/*
    Given an array A of positive integers, call a (contiguous, not
    necessarily distinct) subarray of A good if the number of different
    integers in that subarray is exactly K.

    (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

    Return the number of good subarrays of A. 

    Example 1:
        Input: A = [1,2,1,2,3], K = 2
        Output: 7
        Explanation:
            Subarrays formed with exactly 2 different integers: [1,2],
            [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].

    Example 2:
        Input: A = [1,2,1,3,4], K = 3
        Output: 3
        Explanation:
            Subarrays formed with exactly 3 different integers:
            [1,2,1,3], [2,1,3], [1,3,4].

    Note:
        1 <= A.length <= 20000
        1 <= A[i] <= A.length
        1 <= K <= A.length

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/subarrays-with-k-different-integers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    利用滑动窗口的范式，可以得到 “最多” 包含 k 个唯一数字的子串个数。
    那么 “最多” 包含 k 个唯一数字的子串个数，减去 “最多” 包含 k - 1 个
    唯一数字的子串个数，就是 “恰好” 包含 k 个唯一数字的子串个数。
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
private:
    int subarraysWithAtMostKDistinct(vector<int>& A, int K) {
        int count = 0;
        int left = 0;
        int right = 0;
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator iter;

        while (right < (int) A.size()) {
            iter = map.find(A[right]);
            if (iter == map.end()) {
                map.insert(std::make_pair(A[right], 1));
            } else {
                iter->second++;
            }

            while ((int) map.size() > K) {
                iter = map.find(A[left]);
                iter->second--;
                if (!iter->second) {
                    map.erase(iter);
                }

                left++;
            }
            
            count += right - left + 1;

            right++;
        }

        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarraysWithAtMostKDistinct(A, K) - subarraysWithAtMostKDistinct(A, K - 1);
    }
};

int main()
{
    Solution s;
    vector<int> A;

    A = { 1,2,1,2,3 };
    assert(7 == s.subarraysWithKDistinct(A, 2));

    A = { 1,2,1,3,4 };
    assert(3 == s.subarraysWithKDistinct(A, 3));

    return 0;
}
