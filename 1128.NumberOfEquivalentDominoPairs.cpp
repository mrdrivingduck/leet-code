/**
 * @author Mr Dk.
 * @version 2021/01/26

/*
    Given a list of dominoes, dominoes[i] = [a, b] is equivalent to
    dominoes[j] = [c, d] if and only if either (a==c and b==d), or
    (a==d and b==c) - that is, one domino can be rotated to be equal
    to another domino.

    Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
    and dominoes[i] is equivalent to dominoes[j]. 

    Example 1:
        Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
        Output: 1

    Constraints:
        1 <= dominoes.length <= 40000
        1 <= dominoes[i][j] <= 9

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    将所有多米诺骨牌指定为 a < b 的格式，并进行排序，这样相同的多米诺骨牌就相邻了。
    接下来只需要计算有多少个相同的 pair 即可。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

bool comp(vector<int> &v1, vector<int> &v2) {
    return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
}

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // re-format the dominoes.
        for (size_t i = 0; i < dominoes.size(); i++) {
            if (dominoes[i][0] > dominoes[i][1]) {
                int temp = dominoes[i][0];
                dominoes[i][0] = dominoes[i][1];
                dominoes[i][1] = temp;
            }
        }

        std::sort(dominoes.begin(), dominoes.end(), comp);

        int pairs = 0;
        for (size_t i = 0; i < dominoes.size() - 1; i++) {
            size_t j = i + 1;
            for (; j < dominoes.size(); j++) {
                if (dominoes[i] != dominoes[j]) {
                    break;
                }
            }

            // if there are same dominoes.
            // n-same-domino means (n - 1) + (n - 2) + ... + 1 pairs.
            for (size_t k = 1; k < j - i; k++) {
                pairs += k;
            }

            i = j - 1;
        }

        return pairs;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> dominoes;

    dominoes = { {2,2},{1,2},{1,2},{1,1},{1,2},{1,1},{2,2} };
    assert(5 == s.numEquivDominoPairs(dominoes));

    dominoes = { { 1,2 }, { 2,1 }, { 3,4 }, { 5,6 } };
    assert(1 == s.numEquivDominoPairs(dominoes));

    return 0;
}
