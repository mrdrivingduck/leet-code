/**
 * @author Mr Dk.
 * @version 2020/11/07
 */

/*
    输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回
    true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

    参考以下这颗二叉搜索树：

          5
         / \
        2   6
       / \
      1  3

    示例 1：

    输入: [1,6,3,2,5]
    输出: false

    示例 2：

    输入: [1,3,2,6,5]
    输出: true

    提示：
    数组长度 <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    后序遍历的顺序：左子树、右子树、根结点。倒过来：根结点、右子树、左子树。
    相当于先序遍历，只不过先遍历右子树再遍历左子树罢了。那就可以从根结点开始
    切分右左子树，右子树中的数字必须全部大于根结点，左子树中的数字必须全部
    小于根结点。然后递归判断右子树和左子树即可。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        return judge(postorder, 0, postorder.size());
    }

    bool judge(vector<int>& seq, int index, int len) {
        if (len <= 1) {
            return true;
        }

        int root = seq[index];
        int left_len = 0;
        int right_len = 0;
        int left_index = index + 1;
        int right_index;

        while (left_index + left_len < index + len && seq[left_index + left_len] >= root) {
            left_len++;
        }

        right_index = left_index + left_len;
        while (right_index + right_len < index + len) {
            if (seq[right_index + right_len] > root) {
                return false;
            }
            right_len++;
        }

        return (left_len > 1 ? judge(seq, left_index, left_len) : true) &&
                (right_len > 1 ? judge(seq, right_index, right_len) : true);
    }
};

int main()
{
    Solution s;

    vector<int> vector = { 1,6,3,2,5 };
    cout << s.verifyPostorder(vector) << endl;

    vector = { 1,3,2,6,5 };
    cout << s.verifyPostorder(vector) << endl;

    vector = { 5, 2, -17, -11, 25, 76, 62, 98, 92, 61 };
    cout << s.verifyPostorder(vector) << endl;

    return 0;
}