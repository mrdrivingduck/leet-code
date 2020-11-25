/**
 * @author Mr Dk.
 * @version 2020/11/25
 */

/*
    Given a string s. You should re-order the string using the following
    algorithm:

    1. Pick the smallest character from s and append it to the result.
    2. Pick the smallest character from s which is greater than the last
        appended character to the result and append it.
    3. Repeat step 2 until you cannot pick more characters.
    4. Pick the largest character from s and append it to the result.
    5. Pick the largest character from s which is smaller than the last
        appended character to the result and append it.
    6. Repeat step 5 until you cannot pick more characters.
    7. Repeat the steps from 1 to 6 until you pick all characters from s.

    In each step, If the smallest or the largest character appears more
    than once you can choose any occurrence and append it to the result.

    Return the result string after sorting s with this algorithm.

    Example 1:
        Input: s = "aaaabbbbcccc"
        Output: "abccbaabccba"
        Explanation: After steps 1, 2 and 3 of the first iteration,
            result = "abc"
            After steps 4, 5 and 6 of the first iteration, result = "abccba"
            First iteration is done. Now s = "aabbcc" and we go back to step 1
            After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
            After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"

    Example 2:
        Input: s = "rat"
        Output: "art"
        Explanation: The word "rat" becomes "art" after re-ordering it with
                the mentioned algorithm.

    Example 3:
        Input: s = "leetcode"
        Output: "cdelotee"

    Example 4:
        Input: s = "ggggggg"
        Output: "ggggggg"

    Example 5:
        Input: s = "spo"
        Output: "ops"

    Constraints:
        1 <= s.length <= 500
        s contains only lower-case English letters.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/increasing-decreasing-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    虽然是个简单题，但是其思想已经在相关的复杂题目中出现了很多次。在字符串相关的题
    目中，字母桶是一个非常常用的技术。只需要一个长度为 26 的数组，就可以记录整个
    字符串中字母出现的信息。

    先统计一次字符串中的所有字母出现的信息，然后依次正序和逆序遍历数组，提取出数量
    不为 0 的字符，直到所有字符的数量都为 0 为止。
 */

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    string sortString(string s) {
        vector<int> bucket(26, 0);

        for (size_t i = 0; i < s.length(); i++) {
            bucket[s[i] - 'a']++;
        }

        string result;
        bool all_null = false;

        while (!all_null) {
            all_null = true;
            for (size_t i = 0; i < bucket.size(); i++) {
                if (bucket[i] > 0) {
                    all_null = false;
                    bucket[i]--;
                    result.push_back('a' + i);
                }
            }

            if (all_null) {
                break;
            }

            all_null = true;
            for (int i = bucket.size() - 1; i >= 0; i--) {
                if (bucket[i] > 0) {
                    all_null = false;
                    bucket[i]--;
                    result.push_back('a' + i);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    cout << s.sortString("aaaabbbbcccc") << endl;
    cout << s.sortString("rat") << endl;
    cout << s.sortString("leetcode") << endl;
    cout << s.sortString("gggggggg") << endl;
    cout << s.sortString("spo") << endl;
    cout << s.sortString("") << endl;

    return 0;
}
