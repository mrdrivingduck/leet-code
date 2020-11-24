/**
 * @author Mr Dk.
 * @version 2020.11.24
 */

/*
    Given a complete binary tree, count the number of nodes.

    Note:
        Definition of a complete binary tree from Wikipedia:
        In a complete binary tree every level, except possibly the last,
        is completely filled, and all nodes in the last level are as far
        left as possible. It can have between 1 and 2h nodes inclusive
        at the last level h.

    Example:
        Input: 
              1
            / \
          2   3
         / \  /
        4  5 6

        Output: 6

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    利用满二叉树的性质：结点个数等于 2^(h + 1) - 1，其中 h 为二叉树的高度。
    完全二叉树的性质：如果左右子树高度一致，那么可能空缺的结点一定发生在右子树上，
    左子树肯定是高度减 1 的满二叉树，递归验证右子树；如果左右子树高度不一致，那么
    右子树一定是高度减 1 的满二叉树，左子树是一个完全二叉树，递归验证左子树即可。
 */

#include <iostream>
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

    // only for testing
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int get_tree_height(TreeNode *root) {
        int height = 0;
        if (!root) {
            return -1;
        }
        while (root->left) {
            height++;
            root = root->left;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int left_height = get_tree_height(root->left);
        int right_height = get_tree_height(root->right);

        if (left_height > right_height) {
            // right tree is a full-binary-tree
            // consider left tree only
            return 1 + countNodes(root->left) + (1 << (right_height + 1)) - 1;
        } else {
            // left tree is a full-binary tree
            // consider right tree only
            return 1 + (1 << (left_height + 1)) - 1 + countNodes(root->right);
        }
    }

    /**
     * for testing
     */
    void traverse(TreeNode *root) {
        cout << root->val << endl;
        if (root->left) {
            traverse(root->left);
        }
        if (root->right) {
            traverse(root->right);
        }
    }
};

int main()
{
    Solution s;

    TreeNode *left, *right;

    left = new TreeNode(4);
    right = new TreeNode(5);
    left = new TreeNode(2, left, right);

    right = new TreeNode(6);
    right = new TreeNode(3, right, NULL);

    left = new TreeNode(1, left, right);

    cout << s.countNodes(left) << endl;

    return 0;
}