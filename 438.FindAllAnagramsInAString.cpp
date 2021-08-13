/**
 * @author Mr Dk.
 * @version 2021/08/13
 */

/*
    Given two strings s and p, return an array of all the start indices of
    p's anagrams in s. You may return the answer in any order.

    Example 1:
        Input: s = "cbaebabacd", p = "abc"
        Output: [0,6]
        Explanation:
            The substring with start index = 0 is "cba", which is an anagram
            of "abc".
            The substring with start index = 6 is "bac", which is an anagram
            of "abc".

    Example 2:
        Input: s = "abab", p = "ab"
        Output: [0,1,2]
        Explanation:
            The substring with start index = 0 is "ab", which is an anagram
            of "ab".
            The substring with start index = 1 is "ba", which is an anagram
            of "ab".
            The substring with start index = 2 is "ab", which is an anagram
            of "ab".

    Constraints:
        1 <= s.length, p.length <= 3 * 104
        s and p consist of lowercase English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    将目标串构造为一个桶。在模式串上构造一个滑动窗口，并维护长度为目标串的滑动窗口。
    在桶内去掉滑动窗口内的字符。如果某个窗口能让桶内全为 0，那么就找到了一个变位词，
    将窗口左端点记录到结果中即可。
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
public:
    vector<int> findAnagrams(string s, string p) {
        int bucket[26] = { 0 };
        vector<int> result;

        for (size_t i = 0; i < p.length(); i++) {
            bucket[p[i] - 'a']++;
        }

        size_t left = 0;
        size_t right = 0;

        while (right < s.size()) {
            bucket[s[right] - 'a']--;
            right++;

            if (right - left < p.length()) {
                continue;
            }

            bool all_zero = true;
            for (size_t i = 0; i < 26; i++) {
                if (bucket[i]) {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero) {
                result.push_back(left);
            }

            bucket[s[left] - 'a']++;
            left++;
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> anagrams;

    anagrams = { 0,6 };
    assert(anagrams == s.findAnagrams("cbaebabacd", "abc"));

    anagrams = { 0,1,2 };
    assert(anagrams == s.findAnagrams("abab", "ab"));

    return 0;
}
