/**
 * @author Mr Dk.
 * @version 2020/10/20
 */

/*
    输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中
    都不含重复的数字。

    例如，给出

    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]
    返回如下的二叉树：

         3
        / \
       9  20
         /  \
        15   7
     

    限制：

    0 <= 节点个数 <= 5000

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = NULL;
        if (preorder.size() < 1) {
            return root;
        }

        return buildNode(preorder, inorder, 0, 0, preorder.size());
    }

    /*
        将两个数组进行分段，然后递归构造左右子树。所以需要两个 *_start 指示
        子数组的开始位置，以及 len 用于指示子数组的长度。

        先序数组的第一个元素就是根结点，然后在中序数组中找到根结点后，左右两边
        的数组分别就是左右子树的数组。
    */

    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder,
            int pre_start, int in_start, int len) {

        TreeNode *root = new TreeNode(preorder[pre_start]);

        for (int i = 0; i < len; i++) {
            if (root->val == inorder[in_start + i]) {
                int left_len = i;
                int right_len = len - i - 1;

                if (left_len > 0) {
                    root->left = buildNode(preorder, inorder, pre_start + 1, in_start, left_len);
                }
                if (right_len > 0) {
                    root->right = buildNode(preorder, inorder, pre_start + 1 + left_len, in_start + 1 + left_len, right_len);
                }

                return root;
            }
        }

        return root;
    }

    void traverseTest(TreeNode *root) {
        if (!root) {
            cout << "Empty" << endl;
        }

        cout << root->val << endl;
        if (root->left) {
            traverseTest(root->left);
        }
        if (root->right) {
            traverseTest(root->right);
        }
    }
};

int main()
{
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };


    Solution s;
    s.traverseTest(s.buildTree(preorder, inorder));

    return 0;
}