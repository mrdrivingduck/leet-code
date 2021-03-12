/**
 * @author Mr Dk.
 * @version 2021/03/12
 */

/*
    One way to serialize a binary tree is to use pre-order traversal.
    When we encounter a non-null node, we record the node's value. If
    it is a null node, we record using a sentinel value such as #.

            _9_
           /   \
          3     2
        / \   / \
       4   1  #  6
     / \ / \   / \
    # # # #   # #

    For example, the above binary tree can be serialized to the string
    "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

    Given a string of comma separated values, verify whether it is a
    correct preorder traversal serialization of a binary tree. Find an
    algorithm without reconstructing the tree.

    Each comma separated value in the string must be either an integer
    or a character '#' representing null pointer.

    You may assume that the input format is always valid, for example
    it could never contain two consecutive commas such as "1,,3".

    Example 1:
        Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
        Output: true

    Example 2:
        Input: "1,#"
        Output: false

    Example 3:
        Input: "9,#,#,1"
        Output: false

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    模拟建树顺序但不真正建树。遇到叶子结点则返回上级。到最后，应当在建立
    合法二叉树的前提下，恰好把所有的结点用完。
 */

#include <cassert>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

class Solution {
    bool is_valid(vector<string> &nodes, size_t &index) {
        if (index >= nodes.size()) {
            return false;
        }

        if (nodes[index++] == "#") {
            return true;
        }
        
        return is_valid(nodes, index) && is_valid(nodes, index);
    }
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string line;
        vector<string> nodes;
        while (getline(ss, line, ',')) {
            nodes.push_back(line);
        }

        size_t i = 0;
        return is_valid(nodes, i) && i == nodes.size();
    }
};

int main()
{
    Solution s;
    
    assert(true == s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));

    assert(false == s.isValidSerialization("1,#"));

    assert(false == s.isValidSerialization("9,#,#,1"));

    return 0;
}
