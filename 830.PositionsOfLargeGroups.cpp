/**
 * @author Mr Dk.
 * @version 2021/01/05
 */

/*
    In a string s of lowercase letters, these letters form consecutive groups
    of the same character.

    For example, a string like s = "abbxxxxzyy" has the groups "a", "bb",
    "xxxx", "z", and "yy".

    A group is identified by an interval [start, end], where start and end
    denote the start and end indices (inclusive) of the group. In the above
    example, "xxxx" has the interval [3,6].

    A group is considered large if it has 3 or more characters.

    Return the intervals of every large group sorted in increasing order by start index.

    Example 1:
        Input: s = "abbxxxxzzy"
        Output: [[3,6]]
        Explanation: "xxxx" is the only large group with start index 3 and end index 6.

    Example 2:
        Input: s = "abc"
        Output: []
        Explanation: We have groups "a", "b", and "c", none of which are large groups.

    Example 3:
        Input: s = "abcdddeeeeaabbbcd"
        Output: [[3,5],[6,9],[12,14]]
        Explanation: The large groups are "ddd", "eeee", and "bbb".

    Example 4:
        Input: s = "aba"
        Output: []

    Constraints:
        1 <= s.length <= 1000
        s contains lower-case English letters only.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/positions-of-large-groups
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    遍历一遍字符串即可，记录相同字母开始的区间，在字母不同时封闭区间并判断
    是否要加入到结果集合中。

    循环结束后不要忘记判断最后一个区间是否符合要求。
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
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> groups;

        int length = 1;
        int start = 0;
        for (int i = 1; i < (int) s.length(); i++) {
            if (s[i] == s[start]) {
                length++;
            } else {
                if (length >= 3) {
                    groups.push_back({ start, i - 1 });
                }
                start = i;
                length = 1;
            }
        }

        if (length >= 3) {
            groups.push_back({ start, (int) s.length() - 1 });
        }

        return groups;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> groups;
    vector<vector<int>> result;

    result = { { 3,6 } };
    assert(result == s.largeGroupPositions("abbxxxxzzy"));

    result = {  };
    assert(result == s.largeGroupPositions("abc"));

    result = { { 3,5 }, { 6,9 }, { 12,14 } };
    assert(result == s.largeGroupPositions("abcdddeeeeaabbbcd"));

    result = {  };
    assert(result == s.largeGroupPositions("aba"));

    return 0;
}
