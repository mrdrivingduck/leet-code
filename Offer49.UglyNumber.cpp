/**
 * @author Mr Dk.
 * @version 2021/01/21
 */

/*
    我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

    示例:
        输入: n = 10
        输出: 12
        解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

    说明:  
        1 是丑数。
        n 不超过1690。

    注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/chou-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    维护一个堆。每次从堆中弹出一个数，将这个数乘以 2、3 和 5 后再加入堆。另外还需要维护一个
    hash 表记录出现过的数字，防止出现过的数字重新加入堆。

    由于乘以 2、3 或 5 后可能会出现溢出，所以堆和 hash 表都使用了 long long 类型。
*/

#include <cassert>

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> queue;
        unordered_set<long long> set;

        set.insert(1);
        queue.reserve(n);
        queue.push_back(1);
        std::make_heap(queue.begin(), queue.end(), std::greater<long long>());
        
        for (int i = 1; i < n; i++) {
            long long top = queue[0];
            std::pop_heap(queue.begin(), queue.end(), std::greater<long long>());
            queue.pop_back();

            long long ugly_next = 2 * top;
            if (set.find(ugly_next) == set.end()) {
                set.insert(ugly_next);
                queue.push_back(ugly_next);
                std::push_heap(queue.begin(), queue.end(), std::greater<long long>());
            }

            ugly_next = 3 * top;
            if (set.find(ugly_next) == set.end()) {
                set.insert(ugly_next);
                queue.push_back(ugly_next);
                std::push_heap(queue.begin(), queue.end(), std::greater<long long>());
            }

            ugly_next = 5 * top;
            if (set.find(ugly_next) == set.end()) {
                set.insert(ugly_next);
                queue.push_back(ugly_next);
                std::push_heap(queue.begin(), queue.end(), std::greater<long long>());
            }
        }

        return queue[0];
    }
};

int main()
{
    Solution s;
    
    assert(1 == s.nthUglyNumber(1));
    assert(12 == s.nthUglyNumber(10));

    return 0;
}
