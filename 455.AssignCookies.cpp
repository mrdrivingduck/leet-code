/**
 * @author Mr Dk.
 * @version 2020/12/25 🎅
 */

/*
    Assume you are an awesome parent and want to give your children some
    cookies. But, you should give each child at most one cookie.

    Each child i has a greed factor g[i], which is the minimum size of a
    cookie that the child will be content with; and each cookie j has a
    size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i,
    and the child i will be content. Your goal is to maximize the number
    of your content children and output the maximum number.

    Example 1:
        Input: g = [1,2,3], s = [1,1]
        Output: 1
        Explanation: You have 3 children and 2 cookies. The greed factors
                of 3 children are 1, 2, 3. And even though you have 2 cookies,
                since their size is both 1, you could only make the child
                whose greed factor is 1 content. You need to output 1.

    Example 2:
        Input: g = [1,2], s = [1,2,3]
        Output: 2
        Explanation: You have 2 children and 3 cookies. The greed factors
                of 2 children are 1, 2. You have 3 cookies and their sizes
                are big enough to gratify all of the children, You need to
                output 2.

    Constraints:
        1 <= g.length <= 3 * 104
        0 <= s.length <= 3 * 104
        1 <= g[i], s[j] <= 231 - 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/assign-cookies
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    对孩子的胃口和饼干大小进行排序，然后从最小的饼干开始依次分发给孩子。
    如果一块饼干满足不了孩子的胃口，那么这块饼干也肯定满足不了之后孩子
    的胃口。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        size_t i = 0;
        size_t j = 0;
        int count = 0;

        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                count++;
                i++; // one child satisfied
            }
            j++; // next cookie
        }

        return count;
    }
};

int main() {
    Solution s;    
    vector<int> greed_factor;
    vector<int> cookies;

    greed_factor = { 1,2,3 };
    cookies = { 1,1 };
    assert(1 == s.findContentChildren(greed_factor, cookies));

    greed_factor = { 1,2 };
    cookies = { 1,2,3 };
    assert(2 == s.findContentChildren(greed_factor, cookies));

    return 0;
}
