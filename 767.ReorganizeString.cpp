/**
 * @author Mr Dk.
 * @version 2020/11/30
 */

/*
    Given a string S, check if the letters can be rearranged so that two
    characters that are adjacent to each other are not the same.

    If possible, output any possible result.  If not possible, return the
    empty string.

    Example 1:
        Input: S = "aab"
        Output: "aba"

    Example 2:
        Input: S = "aaab"
        Output: ""

    Note:
        S will consist of lowercase letters and have length in range [1, 500].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reorganize-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    统计出数量最多的字母。如果余下的所有字符足够将这些字符分隔开 (数量至少为数量最多的字母
    的数量 - 1)，那么就能够满足题目要求。依次将次多的字符插进字符串中即可。首先要尽可能保证
    数量最多的字母被分隔开，满足该条件后，剩余字符可以随意分隔插入。
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::size_t;

struct character {
    char ch;
    int number;
};

// reverse order
bool cmp(struct character &c1, struct character &c2)
{
    return c1.number > c2.number;
}

class Solution {
public:
    string reorganizeString(string S) {
        vector<character> bucket;
        bucket.reserve(26);
        // initialize the bucket
        for (size_t i = 0; i < 26; i++) {
            struct character ch { (char) ('a' + i), 0 };
            bucket.push_back(ch);
        }
        // calculate the number of chars
        for (size_t i = 0; i < S.length(); i++) {
            bucket[S[i] - 'a'].number++;
        }

        sort(bucket.begin(), bucket.end(), cmp);

        // initialize the char with largest number
        string res(bucket[0].number, bucket[0].ch);
        int max_number = bucket[0].number;
        int pos = 1;

        for (size_t i = 1; i < bucket.size(); i++) {
            // no more chars
            if (bucket[i].number == 0) {
                break;
            }
            // char with the largest number has all been splitted
            // now the insert can start from the begining
            if (max_number < 1) {
                pos = 1;
            }

            // insert in the order of numbers
            for (int j = 0; j < bucket[i].number; j++) {
                res.insert(pos, 1, bucket[i].ch);
                max_number--;
                pos = (pos + 2) % res.length();
            }
        }

        // char with the largest number has not been splitted
        if (max_number > 1) {
            return "";
        }

        return res;
    }
};

int main()
{
    Solution s;
    string str;
    
    str = "aab";
    cout << s.reorganizeString(str) << endl;

    str = "aaab";
    cout << s.reorganizeString(str) << endl;

    str = "vvvlo";
    cout << s.reorganizeString(str) << endl;

    str = "aaabbbcc";
    cout << s.reorganizeString(str) << endl;
    
    str = "ogccckcwmbmxtsbmozli";
    cout << s.reorganizeString(str) << endl;

    return 0;
}
