/**
 * @author Mr Dk.
 * @version 2020/11/03
 */

/*
    输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
    假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1}
    是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

    示例 1：

    输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    输出：true
    解释：我们可以按以下顺序执行：
        push(1), push(2), push(3), push(4), pop() -> 4,
        push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1


    示例 2：

    输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
    输出：false
    解释：1 不能在 2 之前弹出。
     

    提示：

    0 <= pushed.length == popped.length <= 1000
    0 <= pushed[i], popped[i] < 1000
    pushed 是 popped 的排列。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    压栈直至 pop 序列的当前元素，然后 pop，依此类推。当 push 序列已经结束，而 pop 序列
    还未结束时，说明当前序列已经不匹配，立刻退出。
*/

#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        size_t i = 0, j = 0;
        stack<int> stack;

        // 遍历 pop 序列
        while (j < popped.size()) {
            // 压栈直至栈顶等于 pop 序列当前元素
            while (i < pushed.size() && (stack.empty() || stack.top() != popped[j])) {
                stack.push(pushed[i]);
                i++;
            }
            // Push 序列已经压完，或栈顶元素已无法满足 pop 序列，失败
            if (stack.empty() || stack.top() != popped[j]) {
                return false;
            }

            // 弹栈，检查 pop 序列的下一个元素
            stack.pop();
            j++;
        }
        
        return true;
    }
};

int main()
{
    Solution s;

    vector<int> pushed, popped;

    pushed = { 1,2,3,4,5 };
    popped = { 4,5,3,2,1 };
    cout << s.validateStackSequences(pushed, popped) << endl;

    pushed = { 1,2,3,4,5 };
    popped = { 4,3,5,1,2 };
    cout << s.validateStackSequences(pushed, popped) << endl;

    return 0;
}