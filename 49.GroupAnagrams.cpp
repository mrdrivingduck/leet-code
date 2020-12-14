/**
 * @author Mr Dk.
 * @version 2020/12/14
 */

/*
    Given an array of strings strs, group the anagrams together. You can
    return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a
    different word or phrase, typically using all the original letters
    exactly once.

    Example 1:
        Input: strs = ["eat","tea","tan","ate","nat","bat"]
        Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    Example 2:
        Input: strs = [""]
        Output: [[""]]

    Example 3:
        Input: strs = ["a"]
        Output: [["a"]]

    Constraints:
        1 <= strs.length <= 104
        0 <= strs[i].length <= 100
        strs[i] consists of lower-case English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/group-anagrams
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    很显然，将字母组合相同的所有字符串的相同点作为 key，维护在哈希表中。
    最简单的相同点是对每个字符串进行排序，字母组合相同的字符串排序后一定
    是相同的。

    也尝试了桶 - 字母组合相同的字符串的桶状况也一定相同。没实现好，速度
    稍微慢了点。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        unordered_map<string, vector<string>>::iterator iter;

        for (size_t i = 0; i < strs.size(); i++) {
            string str(strs[i]);
            std::sort(str.begin(), str.end());
            iter = map.find(str);
            if (iter == map.end()) {
                vector<string> list = { strs[i] };
                map.insert(std::make_pair(str, list));
            } else {
                iter->second.push_back(strs[i]);
            }
        }

        vector<vector<string>> result;
        result.reserve(map.size());
        for (iter = map.begin(); iter != map.end(); iter++) {
            result.push_back(iter->second);
        }

        return result;
    }

    // vector<vector<string>> groupAnagrams(vector<string> &strs) {
    //     unordered_map<string, vector<string>> map;
    //     unordered_map<string, vector<string>>::iterator iter;

    //     for (size_t i = 0; i < strs.size(); i++) {
    //         int bucket[26] = { 0 };
    //         for (size_t j = 0; j < strs[i].size(); j++) {
    //             bucket[strs[i][j] - 'a']++;
    //         }
    //         string str;
    //         for (int j = 0; j < 26; j++) {
    //             if (bucket[j] < 10) {
    //                 str.push_back('0');
    //             }
    //             str.append(std::to_string(bucket[j]));
    //         }

    //         iter = map.find(str);
    //         if (iter == map.end()) {
    //             vector<string> list = { strs[i] };
    //             map.insert(std::make_pair(str, list));
    //         } else {
    //             iter->second.push_back(strs[i]);
    //         }
    //     }

    //     vector<vector<string>> result;
    //     result.reserve(map.size());
    //     for (iter = map.begin(); iter != map.end(); iter++) {
    //         result.push_back(iter->second);
    //     }

    //     return result;
    // }
};

int main()
{
    Solution s;
    
    vector<string> strs = { "bdddddddddd", "bbbbbbbbbbc" };
    cout << s.groupAnagrams(strs).size() << endl;

    return 0;
}
