/**
 * @author Mr Dk.
 * @version 2020/12/22
 */

/*
    Given a binary tree, return the zigzag level order traversal of its
    nodes' values. (ie, from left to right, then right to left for the
    next level and alternate between).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
      15   7

    return its zigzag level order traversal as:
        [
            [3],
            [20,9],
            [15,7]
        ]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    层序遍历即可。一次正序，一次逆序。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        vector<TreeNode *> order = { root };
        vector<TreeNode *> reverse;
        while (!order.empty() || !reverse.empty()) {
            if (!order.empty()) {
                vector<int> level;
                level.reserve(order.size());
                for (size_t i = 0; i < order.size(); i++) {
                    level.push_back(order[i]->val);
                    if (order[i]->left) {
                        reverse.push_back(order[i]->left);
                    }
                    if (order[i]->right) {
                        reverse.push_back(order[i]->right);
                    }
                }
                order.clear();
                result.push_back(level);
            }
            if (!reverse.empty()) {
                vector<int> level;
                level.reserve(reverse.size());
                for (size_t i = 0; i < reverse.size(); i++) {
                    level.push_back(reverse[i]->val);
                    if (reverse[i]->left) {
                        order.push_back(reverse[i]->left);
                    }
                    if (reverse[i]->right) {
                        order.push_back(reverse[i]->right);
                    }
                }
                reverse.clear();
                std::reverse(level.begin(), level.end());
                result.push_back(level);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    TreeNode *left, *right, *root;

    left = new TreeNode(15);
    right = new TreeNode(7);
    right = new TreeNode(20, left, right);
    left = new TreeNode(9);
    root = new TreeNode(3, left, right);

    vector<vector<int>> result = s.zigzagLevelOrder(root);

    assert(3 == result.size());
    assert(3 == result[0][0]);
    assert(20 == result[1][0]);
    assert(9 == result[1][1]);
    assert(15 == result[2][0]);
    assert(7 == result[2][1]);
    
    return 0;
}