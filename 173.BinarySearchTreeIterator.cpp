/**
 * @author Mr Dk.
 * @version 2021/03/28
 */

/*
    Implement the BSTIterator class that represents an iterator over the
    in-order traversal of a binary search tree (BST):

    BSTIterator(TreeNode root) Initializes an object of the BSTIterator
    class. The root of the BST is given as part of the constructor. The
    pointer should be initialized to a non-existent number smaller than
    any element in the BST.
    boolean hasNext() Returns true if there exists a number in the traversal
    to the right of the pointer, otherwise returns false.
    int next() Moves the pointer to the right, then returns the number at
    the pointer.
    Notice that by initializing the pointer to a non-existent smallest
    number, the first call to next() will return the smallest element in the BST.

    You may assume that next() calls will always be valid. That is, there
    will be at least a next number in the in-order traversal when next() is called. 

    Example 1:
        Input
            ["BSTIterator", "next", "next", "hasNext", "next", "hasNext",
            "next", "hasNext", "next", "hasNext"]
            [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [],
            [], [], []]
        Output
            [null, 3, 7, true, 9, true, 15, true, 20, false]

    Explanation
        BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
        bSTIterator.next();    // return 3
        bSTIterator.next();    // return 7
        bSTIterator.hasNext(); // return True
        bSTIterator.next();    // return 9
        bSTIterator.hasNext(); // return True
        bSTIterator.next();    // return 15
        bSTIterator.hasNext(); // return True
        bSTIterator.next();    // return 20
        bSTIterator.hasNext(); // return False

    Constraints:
        The number of nodes in the tree is in the range [1, 105].
        0 <= Node.val <= 106
        At most 105 calls will be made to hasNext, and next.

    Follow up:
        Could you implement next() and hasNext() to run in average O(1) time and
        use O(h) memory, where h is the height of the tree?

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-search-tree-iterator
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    用栈模拟中序遍历，实现迭代。current 指针指向正在遍历的结点，如果该指针为空意味着
    遍历结束。栈用于保存左子树正在被遍历但结点本身还没有被遍历的结点。在结点本身被遍历
    后，将 current 指向右子树，当前结点无需入栈：因为当前结点右子树遍历完毕后，将直接
    回溯到当前结点的上游结点，无需再次访问当前结点了。
 */

#include <cassert>

#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::endl;
using std::stack;
using std::vector;

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

class BSTIterator {
    TreeNode *current;
    stack<TreeNode *> _stack;
public:
    BSTIterator(TreeNode* root) {
        current = root;
        
        // go to the first node to be accessed
        while (current->left) {
            _stack.push(current);
            current = current->left;
        }
    }
    
    int next() {
        int result = current->val; // save the result

        if (current->right) {
            // go to the right child
            // no need to push into stack anymore
            current = current->right;

            // go to the next node to be accessed
            while (current->left) {
                _stack.push(current);
                current = current->left;
            }
        } else {
            if (!_stack.empty()) {
                // go back to parent
                current = _stack.top();
                _stack.pop();
            } else {
                // no parent to go back
                current = NULL;
            }
        }

        return result;
    }
    
    bool hasNext() {
        return current != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

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

    BSTIterator *iter = new BSTIterator(root);
    vector<int> in_order = { 1,3,4,5,8 };
    size_t i = 0;
    while (iter->hasNext()) {
        assert(in_order[i] == iter->next());
        i++;
    }
    delete iter;

    clean_up(root);

    return 0;
}
