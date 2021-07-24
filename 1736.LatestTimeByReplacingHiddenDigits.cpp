/**
 * @author Mr Dk.
 * @version 2021/07/24
 */

/*
    You are given a string time in the form of hh:mm, where some of the
    digits in the string are hidden (represented by ?).

    The valid times are those inclusively between 00:00 and 23:59.

    Return the latest valid time you can get from time by replacing the
    hidden digits. 

    Example 1:
        Input: time = "2?:?0"
        Output: "23:50"
        Explanation:
            The latest hour beginning with the digit '2' is 23 and the
            latest minute ending with the digit '0' is 50.

    Example 2:
        Input: time = "0?:3?"
        Output: "09:39"

    Example 3:
        Input: time = "1?:22"
        Output: "19:22"

    Constraints:
        time is in the format hh:mm.
        It is guaranteed that you can produce a valid time from the given
        string.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    从高位向低位枚举即可，注意需要考虑到所有可能。
*/

#include <cassert>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            if (time[1] != '?' && time[1] >= '4') {
                time[0] = '1';
            } else {
                time[0] = '2';
            }
        }
        if (time[1] == '?') {
            if (time[0] == '2') {
                time[1] = '3';
            } else {
                time[1] = '9';
            }
        }
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }

        return time;
    }
};

int main()
{
    Solution s;
    string time;

    time = "2?:?0";
    assert("23:50" == s.maximumTime(time));

    time = "0?:3?";
    assert("09:39" == s.maximumTime(time));

    time = "1?:22";
    assert("19:22" == s.maximumTime(time));

    time = "?4:03";
    assert("14:03" == s.maximumTime(time));

    return 0;
}
