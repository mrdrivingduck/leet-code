/**
 * @author Mr Dk.
 * @version 2021/08/10
 */

/*
    Given a string array words, return the maximum value of length(word[i]) *
    length(word[j]) where the two words do not share common letters. If no
    such two words exist, return 0.

    Example 1:
        Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
        Output: 16
        Explanation: The two words can be "abcw", "xtfn".

    Example 2:
        Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
        Output: 4
        Explanation: The two words can be "ab", "cd".

    Example 3:
        Input: words = ["a","aa","aaa","aaaa"]
        Output: 0
        Explanation: No such pair of words.

    Constraints:
        2 <= words.length <= 1000
        1 <= words[i].length <= 1000
        words[i] consists only of lowercase English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    将每个单词中出现的字符构造为一个 bitmap。将两个 bitmap 做与运算
    就可以知道是否存在重复字母。
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
    int maxProduct(vector<string>& words) {
        vector<int> bitmap(words.size(), 0);

        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = 0; j < words[i].length(); j++) {
                bitmap[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        int product = 0;
        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = i + 1; j < words.size(); j++) {
                if (!(bitmap[i] & bitmap[j])) {
                    product = std::max(product, (int) (words[i].length() * words[j].length()));
                }
            }
        }

        return product;
    }
};

int main()
{
    Solution s;
    vector<string> words;

    words = { "abcw","baz","foo","bar","xtfn","abcdef" };
    assert(16 == s.maxProduct(words));

    words = { "a","ab","abc","d","cd","bcd","abcd" };
    assert(4 == s.maxProduct(words));

    words = { "a","aa","aaa","aaaa" };
    assert(0 == s.maxProduct(words));
    
    return 0;
}
