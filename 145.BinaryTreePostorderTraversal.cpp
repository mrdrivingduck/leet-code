/**
 * @author Mr Dk.
 * @version 2021/03/09
 */

/*
    Given the root of a binary tree, return the postorder traversal of
    its nodes' values. 

    Example 1:
        Input: root = [1,null,2,3]
        Output: [3,2,1]

    Example 2:
        Input: root = []
        Output: []

    Example 3:
        Input: root = [1]
        Output: [1]

    Example 4:
        Input: root = [1,2]
        Output: [2,1]

    Example 5:
        Input: root = [1,null,2]
        Output: [2,1]

    Constraints:
        The number of the nodes in the tree is in the range [0, 100].
        -100 <= Node.val <= 100

    Follow up:
        Recursive solution is trivial, could you do it iteratively?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <stack>
using std::cout;
using std::endl;
using std::vector;
using std::stack;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> order;
    //     if (!root) {
    //         return order;
    //     }
    //     if (root->left) {
    //         vector<int> left = postorderTraversal(root->left);
    //         order.insert(order.end(), left.begin(), left.end());
    //     }
    //     if (root->right) {
    //         vector<int> right = postorderTraversal(root->right);
    //         order.insert(order.end(), right.begin(), right.end());
    //     }
    //     order.push_back(root->val);
    //     return order;
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post_order;
        stack<TreeNode *> nodes;
        stack<bool> second_push;
        
        bool second = false;
        while (!nodes.empty() || root) {
            if (root) {
                nodes.push(root);
                second_push.push(false);
                root = root->left;
            } else {
                root = nodes.top();
                second = second_push.top();
                nodes.pop();
                second_push.pop();
                
                if (!second) {
                    nodes.push(root);
                    second_push.push(true);
                    root = root->right;
                } else {
                    post_order.push_back(root->val);
                    root = NULL;
                }
            }
        }

        return post_order;
    }

    /**
     * 递归写法：
     * 
     * void post(TreeNode *root) {
     *     if (root->left) {
     *         post(root->left);
     *     }
     *     if (root->right) {
     *         post(root->right);
     *     }
     *     root->val;
     * }
     * 
     * 非递归写法需要用栈来模拟保存现场和恢复现场。现场包含两部分：局部变量和返回地址。
     * 可以看到，需要保存的局部变量只有一个：root 指针；而需要保存的返回地址可能有
     * 两个：分别在两个递归调用的 post() 之后。将局部变量和下一轮要返回的地址为止
     * 压入栈中，然后将局部变量更新为下一轮循环的模式；在恢复时，从栈中弹出局部变量
     * 和返回地址，将局部变量复原，然后将控制流跳转到相应的返回地址上。
     */
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> order;
//         stack<TreeNode *> nodes;
//         stack<int> flags;
//         int flag = 0;

//         while (root) {
//             if (root->left) {
//                 nodes.push(root);
//                 flags.push(1);
//                 root = root->left;
//                 flag = 0;
//                 continue;
// ret_from_left:
//                 ;
//             }
//             if (root->right) {
//                 nodes.push(root);
//                 flags.push(2);
//                 root = root->right;
//                 flag = 0;
//                 continue;
// ret_from_right:
//                 ;
//             }

//             order.push_back(root->val);

//             // recover
//             if (nodes.empty()) {
//                 break;
//             }
//             root = nodes.top();
//             flag = flags.top();
//             nodes.pop();
//             flags.pop();

//             // next iteration
//             if (flag == 1) {
//                 goto ret_from_left;
//             } else if (flag == 2) {
//                 goto ret_from_right;
//             } // default: from to top
//         }

//         return order;
//     }
};

void clean_up(TreeNode *root) {
    if (root->left) {
        clean_up(root->left);
    }
    if (root->right) {
        clean_up(root->right);
    }
    delete root;
}

int main()
{
    TreeNode *root = NULL;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    left = new TreeNode(1);
    right = new TreeNode(4);
    root = new TreeNode(3, left, right);
    left = root;
    right = new TreeNode(8);
    root = new TreeNode(5, left, right);

    Solution s;
    vector<int> post_order = { 1,4,3,8,5 };
    assert(post_order == s.postorderTraversal(root));

    clean_up(root);

    return 0;
}
