/**
 * @author Mr Dk.
 * @version 2021/07/28
 */

/*
    Given the root of a binary tree, the value of a target node target,
    and an integer k, return an array of the values of all nodes that
    have a distance k from the target node.

    You can return the answer in any order. 

    Example 1:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
        Output: [7,4,1]
        Explanation:
            The nodes that are a distance 2 from the target node (with
            value 5) have values 7, 4, and 1.

    Example 2:
        Input: root = [1], target = 1, k = 3
        Output: []

    Constraints:
        The number of nodes in the tree is in the range [1, 500].
        0 <= Node.val <= 500
        All the values Node.val are unique.
        target is the value of one of the nodes in the tree.
        0 <= k <= 1000


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    遍历整棵树，构造一个 hash table，维护每个节点的相邻节点。
    从目标节点开始广度优先遍历即可。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::queue;

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

TreeNode *build_tree(vector<int> &input) {
    TreeNode *root = NULL;
    queue<TreeNode **> nodes;
    nodes.push(&root);

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] != -1) {
            TreeNode **p = nodes.front();
            *p = new TreeNode(input[i]);
            nodes.push(&((*p)->left));
            nodes.push(&((*p)->right));
            nodes.pop();
        } else {
            nodes.pop();
        }
    }

    return root;
}

TreeNode *find(TreeNode *root, int &target) {
    TreeNode *node = NULL;
    if (root->val == target) {
        return root;
    }
    if (root->left && (node = find(root->left, target)) != NULL) {
        return node;
    }
    if (root->right && (node = find(root->right, target)) != NULL) {
        return node;
    }
    return node;
}

void destroy_node(TreeNode *root) {
    if (root->left) {
        destroy_node(root->left);
    }
    if (root->right) {
        destroy_node(root->right);
    }
    delete(root);
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if (!root) {
            return res;
        }

        unordered_map<int, vector<int>> neighbor;
        dfs(root, -1, neighbor);

        int start = target->val;
        queue<int> current_queue;
        queue<int> next_queue;
        unordered_set<int> unique;
        current_queue.push(start);
        unique.insert(start);

        for (int i = 0; i < k; i++) {
            while (!current_queue.empty()) {
                int node = current_queue.front();
                vector<int> nei = neighbor[node];
                for (size_t j = 0; j < nei.size(); j++) {
                    if (unique.find(nei[j]) == unique.end()) {
                        next_queue.push(nei[j]);
                        unique.insert(nei[j]);
                    }
                }
                current_queue.pop();
            }

            current_queue.swap(next_queue);
        }

        while (!current_queue.empty()) {
            res.push_back(current_queue.front());
            current_queue.pop();
        }

        return res;
    }
private:
    void dfs(TreeNode *root, int parent, unordered_map<int, vector<int>> &neighbor) {
        vector<int> nei;
        if (parent != -1) {
            nei.push_back(parent);
        }
        if (root->left) {
            nei.push_back(root->left->val);
            dfs(root->left, root->val, neighbor);
        }
        if (root->right) {
            nei.push_back(root->right->val);
            dfs(root->right, root->val, neighbor);
        }
        neighbor[root->val] = nei;
    }
};

int main()
{
    Solution s;
    vector<int> input;
    vector<int> output;
    int target;
    int distance;
    TreeNode *root;
    TreeNode *node;

    input = { 3,5,1,6,2,0,8,-1,-1,7,4 };
    output = { 1,7,4 };
    target = 5;
    distance = 2;

    root = build_tree(input);
    node = find(root, target);
    assert(output == s.distanceK(root, node, distance));
    destroy_node(root);

    input = { 1 };
    output = { };
    target = 1;
    distance = 3;

    root = build_tree(input);
    node = find(root, target);
    assert(output == s.distanceK(root, node, distance));
    destroy_node(root);
    
    return 0;
}
