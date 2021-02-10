/**
 * @author Mr Dk.
 * @version 2021/02/10
 */

/*
    Given two strings s1 and s2, write a function to return true if s2
    contains the permutation of s1. In other words, one of the first
    string's permutations is the substring of the second string. 

    Example 1:
        Input: s1 = "ab" s2 = "eidbaooo"
        Output: True
        Explanation: s2 contains one permutation of s1 ("ba").

    Example 2:
        Input:s1= "ab" s2 = "eidboaoo"
        Output: False

    Constraints:
        The input strings only contain lower case letters.
        The length of both given strings is in range [1, 10,000].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/permutation-in-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    找到一个滑动窗口区间，使其能够正好消费桶中的所有字符。
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
private:
    bool check_null(int bucket[]) {
        for (int i = 0; i < 26; i++) {
            if (bucket[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int bucket[26];
        for (int i = 0; i < 26; i++) {
            bucket[i] = 0;
        }

        for (size_t i = 0; i < s1.length(); i++) {
            bucket[s1[i] - 'a']++;
        }

        int left = 0;
        int right = 0;
        while (right < (int) s2.length()) {
            bucket[s2[right] - 'a']--;

            while (left < right && bucket[s2[left] - 'a'] < 0) {
                bucket[s2[left] - 'a']++;
                left++;
            }

            if (check_null(bucket)) {
                return true;
            }

            right++;
        }

        return false;
    }
};

int main()
{
    Solution s;

    assert(false == s.checkInclusion("a", "b"));
    
    assert(true == s.checkInclusion("ab", "eidbaooo"));

    assert(false == s.checkInclusion("ab", "eidboaoo"));

    return 0;
}
