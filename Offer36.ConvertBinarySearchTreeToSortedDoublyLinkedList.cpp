/**
 * @author Mr Dk.
 * @version 2020/11/16
 */

/*
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，
    只能调整树中节点指针的指向。为了让您更好地理解问题，以下面的二叉搜索树为例：

    我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于
    双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
    下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

    特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中
    节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

    注意：本题与主站 426 题相同
        https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

    注意：此题对比原题有改动。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    以中序遍历 BST，用一个值保持记录前一个结点。每次只修改前一个结点的左右指针。最终，将头尾结点串联。
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return NULL;
        }

        Node head;
        Node *n = &head;
        traverse(root, n); // n is the last node.

        n->right = head.right; // last --> first
        head.right->left = n; // last <-- first

        return n->right;
    }

    void traverse(Node *node, Node *&prev) {
        if (!node) {
            return;
        }
        if (node->left) {
            traverse(node->left, prev);
        }

        // Record and modify the previous node.
        node->left = prev;
        prev->right = node;
        prev = node;
        // cout << root->val << endl;

        if (node->right) {
            traverse(node->right, prev);
        }
    }
};

int main()
{
    Node *n, *left, *right;
    left = new Node(1);
    right = new Node(3);
    n = new Node(2, left, right);
    left = n;
    right = new Node(5);
    n = new Node(4, left, right);

    Solution s;
    s.treeToDoublyList(n);

    return 0;
}