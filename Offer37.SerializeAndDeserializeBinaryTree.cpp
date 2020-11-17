/**
 * @author Mr Dk.
 * @version 2020/11/17
 */

/*
    请实现两个函数，分别用来序列化和反序列化二叉树。

    示例: 

    你可以将以下二叉树：

        1
      / \
     2   3
        / \
       4   5

    序列化为 "[1,2,3,null,null,4,5]"

    注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    通过队列，以层次遍历的顺序，进行序列化和反序列化。队列中保存的是结点指针，
    可以根据指针是否为空进行灵活操作。在序列化时，叶子结点的空指针也要被推进
    队列；当空指针出队时，将 null 加入到字符串中，最终，去除结尾所有的 null；
    在反序列化时，空指针不需要被推进队列，每个从队列中 dequeue 的结点消耗字符串
    中的两个元素，直到字符串中元素被消耗完毕。
*/

#include <iostream>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::to_string;
using std::stoi;

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        data.push_back('[');

        // empty tree
        if (!root) {
            data.append("]");
            return data;
        }

        queue<TreeNode *> queue;
        queue.push(root);

        bool first = true; // judge whether to push back ','

        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();

            if (first) {
                first = false;
            } else {
                data.push_back(',');
            }

            if (!node) {
                data.append("null"); // null node (leaves only)
            } else {
                data.append(to_string(node->val)); // not null node
                queue.push(node->left);
                queue.push(node->right);
            }
        }

        // remove the unused null suffix.
        string suffix(",null");
        while (data.size() > suffix.size() &&
                0 == data.compare(
                    data.size() - suffix.size(), suffix.size(), suffix)) {
            data.resize(data.size() - suffix.size());
        }

        data.push_back(']');
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (0 == data.compare("[]")) {
            return NULL;
        }

        size_t token_start = 1;
        size_t token_end = data.find_first_of(",]", token_start);
        string token = data.substr(token_start, token_end - token_start);
        int val = stoi(token);
        token_start = token_end + 1;

        TreeNode *root = new TreeNode(val);
        
        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();

            token_end = data.find_first_of(",]", token_start);
            if (token_end != string::npos) { // there are still elements in list
                token = data.substr(token_start, token_end - token_start);
                token_start = token_end + 1;
                if (token[0] != 'n') { // not-null node
                    val = stoi(token);
                    node->left = new TreeNode(val);
                    queue.push(node->left);
                }
            }

            token_end = data.find_first_of(",]", token_start);
            if (token_end != string::npos) { // there are still elements in list
                token = data.substr(token_start, token_end - token_start);
                token_start = token_end + 1;
                if (token[0] != 'n') { // not-null node
                    val = stoi(token);
                    node->right = new TreeNode(val);
                    queue.push(node->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    TreeNode *n, *left, *right;
    left = new TreeNode(4);
    right = new TreeNode(5);
    n = new TreeNode(3);
    n->left = left;
    n->right = right;
    right = n;
    left = new TreeNode(2);
    n = new TreeNode(1);
    n->left = left;
    n->right = right;

    // n = new TreeNode(1);
    // n = NULL;

    Codec c;
    string str = c.serialize(n);
    n = c.deserialize(str);
    cout << c.serialize(n) << endl;

    return 0;
}