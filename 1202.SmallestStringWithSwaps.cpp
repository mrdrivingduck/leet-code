/**
 * @author Mr Dk.
 * @version 2020/01/11
 */

/*
    You are given a string s, and an array of pairs of indices in the
    string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed)
    of the string.

    You can swap the characters at any pair of indices in the given pairs
    any number of times.

    Return the lexicographically smallest string that s can be changed to
    after using the swaps. 

    Example 1:
        Input: s = "dcab", pairs = [[0,3],[1,2]]
        Output: "bacd"
        Explaination: 
            Swap s[0] and s[3], s = "bcad"
            Swap s[1] and s[2], s = "bacd"

    Example 2:
        Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
        Output: "abcd"
        Explaination: 
            Swap s[0] and s[3], s = "bcad"
            Swap s[0] and s[2], s = "acbd"
            Swap s[1] and s[2], s = "abcd"

    Example 3:
        Input: s = "cba", pairs = [[0,1],[1,2]]
        Output: "abc"
        Explaination: 
            Swap s[0] and s[1], s = "bca"
            Swap s[1] and s[2], s = "bac"
            Swap s[0] and s[1], s = "abc"     

    Constraints:
        1 <= s.length <= 10^5
        0 <= pairs.length <= 10^5
        0 <= pairs[i][0], pairs[i][1] < s.length
        s only contains lower case English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/smallest-string-with-swaps
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    并查集。找出每个字母最终的代表元，每个代表元维护一个优先队列，队列中为该组内的
    所有字母。
    根据字符串中每个位置对应的代表元从相应的优先队列中取出字母，形成字典序尽可能小
    的字符串。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;
using std::priority_queue;

class Solution {
private:
    int find_root(vector<int> &collection, int i) {
        if (collection[i] != i) {
            collection[i] = find_root(collection, collection[i]);
        }
        return collection[i];
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> collection(s.length());
        for (size_t i = 0; i < collection.size(); i++) {
            collection[i] = i;
        }

        for (size_t i = 0; i < pairs.size(); i++) {
            collection[find_root(collection, pairs[i][0])] =
                find_root(collection, pairs[i][1]);
        }

        unordered_map<int,
                priority_queue<
                        char, vector<char>, std::greater<char>>> groups;
        unordered_map<int,
                priority_queue<
                        char, vector<char>, std::greater<char>>>::iterator map_iter;
        for (size_t i = 0; i < collection.size(); i++) {
            collection[i] = find_root(collection, i);
            
            map_iter = groups.find(collection[i]);
            if (map_iter == groups.end()) {
                priority_queue<
                        char, vector<char>, std::greater<char>> queue;
                queue.push(s[i]);
                groups.insert(std::make_pair(collection[i], queue));
            } else {
                map_iter->second.push(s[i]);
            }
        }

        for (size_t i = 0; i < collection.size(); i++) {
            map_iter = groups.find(collection[i]);
            s[i] = map_iter->second.top();
            map_iter->second.pop();
        }
        
        return s;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> pairs;

    pairs = { { 2,3 }, { 3,2 }, { 0,1 }, { 4,0 }, { 3,2 } };
    assert("dqwyt" == s.smallestStringWithSwaps("qdwyt", pairs));

    pairs = { { 0,3 }, { 1,2 } };
    assert("bacd" == s.smallestStringWithSwaps("dcab", pairs));
    
    pairs = { { 0,3 }, { 1,2 }, { 0,2 } };
    assert("abcd" == s.smallestStringWithSwaps("dcab", pairs));

    pairs = { { 0,1 }, { 1,2 } };
    assert("abc" == s.smallestStringWithSwaps("cba", pairs));

    return 0;
}
