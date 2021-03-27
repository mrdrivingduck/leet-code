/**
 * @author Mr Dk.
 * @version 2021/03/27
 */

/*
    Given a non-empty list of words, return the k most frequent elements.

    Your answer should be sorted by frequency from highest to lowest. If
    two words have the same frequency, then the word with the lower
    alphabetical order comes first.

    Example 1:
        Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
        Output: ["i", "love"]
        Explanation:
            "i" and "love" are the two most frequent words.
            Note that "i" comes before "love" due to a lower alphabetical order.

    Example 2:
        Input:
            ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
        Output:
            ["the", "is", "sunny", "day"]
        Explanation:
            "the", "is", "sunny" and "day" are the four most frequent words,
            with the number of occurrence being 4, 3, 2 and 1 respectively.

    Note:
        You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
        Input words contain only lowercase letters.

    Follow up:
        Try to solve it in O(n log k) time and O(n) extra space.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/top-k-frequent-words
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    用 hash table 统计所有单词出现的频率。统计完毕后，使用优先队列 pop 出
    出现频率最高的 k 个单词。注意出现频率相同时，需要根据字母序来排列。因此
    在重载 '<' 运算符时，要注意判断条件。
 */

#include <cassert>

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

struct word_pair {
    string word;
    int freq;

    bool operator<(const word_pair &p) const {
        return freq == p.freq ? word > p.word : freq < p.freq;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash_table;
        unordered_map<string, int>::iterator iter;
        for (size_t i = 0; i < words.size(); i++) {
            iter = hash_table.find(words[i]);
            if (iter == hash_table.end()) {
                hash_table.insert(std::make_pair(words[i], 1));
            } else {
                iter->second++;
            }
        }

        vector<word_pair> pairs;
        pairs.reserve(hash_table.size());
        for (iter = hash_table.begin(); iter != hash_table.end(); iter++) {
            pairs.push_back({ iter->first, iter->second });
        }
        std::make_heap(pairs.begin(), pairs.end());

        vector<string> result;
        result.reserve(k);
        for (int i = 0; i < k; i++) {
            result.push_back(pairs[0].word);
            std::pop_heap(pairs.begin(), pairs.end());
            pairs.pop_back();
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> words;
    vector<string> top_k_words;

    words = { "i", "love", "leetcode", "i", "love", "coding" };
    top_k_words = { "i", "love" };
    assert(top_k_words == s.topKFrequent(words, 2));

    words = {
        "the", "day", "is", "sunny", "the", "the", "the", "sunny",
        "is", "is"
    };
    top_k_words = { "the", "is", "sunny", "day" };
    assert(top_k_words == s.topKFrequent(words, 4));

    return 0;
}
