/**
 * @author Mr Dk.
 * @version 2021/01/31
 */

/*
    Two strings X and Y are similar if we can swap two letters (in different
    positions) of X, so that it equals Y. Also two strings X and Y are
    similar if they are equal.

    For example, "tars" and "rats" are similar (swapping at positions 0 and
    2), and "rats" and "arts" are similar, but "star" is not similar to
    "tars", "rats", or "arts".

    Together, these form two connected groups by similarity: {"tars", "rats",
    "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same
    group even though they are not similar.  Formally, each group is such
    that a word is in the group if and only if it is similar to at least one
    other word in the group.

    We are given a list strs of strings where every string in strs is an
    anagram of every other string in strs. How many groups are there?

    Example 1:
        Input: strs = ["tars","rats","arts","star"]
        Output: 2

    Example 2:
        Input: strs = ["omv","ovm"]
        Output: 1

    Constraints:
        1 <= strs.length <= 100
        1 <= strs[i].length <= 1000
        sum(strs[i].length) <= 2 * 104
        strs[i] consists of lowercase letters only.
        All words in strs have the same length and are anagrams of each other.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/similar-string-groups
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    并查集。通过判断每一对字符串之间的相似性，将字符串归到不同的组中。

    注意，下面的并查集实现方式，最后还需要额外做一次路径压缩。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
private:
    bool similar(string &s1, string &s2) {
        int sum = 0;
        int count = 0;
        for (size_t i = 0; i < s1.length(); i++) {
            int sub = s1[i] - s2[i];
            if (sub) {
                sum += sub;
                count++;

                if (count > 2) {
                    return false;
                }
            }
        }

        return !sum;
    }

    int find(vector<int> &groups, int index) {
        return groups[index] == index ?
                index :
                groups[index] = find(groups, groups[index]);
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        vector<int> groups(strs.size());
        for (size_t i = 0; i < groups.size(); i++) {
            groups[i] = i;
        }

        for (size_t i = 0; i < strs.size(); i++) {
            for (size_t j = i + 1; j < strs.size(); j++) {
                if (similar(strs[i], strs[j])) {
                    groups[find(groups, j)] = find(groups, i);
                }
            }
        }

        for (size_t i = 0; i < strs.size(); i++) {
            groups[i] = find(groups, i);
        }

        std::sort(groups.begin(), groups.end());
        return std::unique(groups.begin(), groups.end()) - groups.begin();
    }
};

int main()
{
    Solution s;
    vector<string> strs;

    strs = { "abc","abc" };
    assert(1 == s.numSimilarGroups(strs));

    strs = { "tars","rats","arts","star" };
    assert(2 == s.numSimilarGroups(strs));

    strs = { "omv","ovm" };
    assert(1 == s.numSimilarGroups(strs));

    return 0;
}
