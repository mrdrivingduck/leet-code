/**
 * @author Mr Dk.
 * @version 2020/11/12
 */

/*
    A linked list is given such that each node contains an additional random
    pointer which could point to any node in the list or null.

    Return a deep copy of the list.

    The Linked List is represented in the input/output as a list of n nodes.
    Each node is represented as a pair of [val, random_index] where:

        val: an integer representing Node.val
        random_index: the index of the node (range from 0 to n-1) where random
                    pointer points to, or null if it does not point to any node.
     
    Example 1:
        Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
        Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

    Example 2:
        Input: head = [[1,1],[2,1]]
        Output: [[1,1],[2,1]]

    Example 3:
        Input: head = [[3,null],[3,0],[3,null]]
        Output: [[3,null],[3,0],[3,null]]

    Example 4:
        Input: head = []
        Output: []
        Explanation: Given linked list is empty (null pointer), so return null.

    Constraints:
        -10000 <= Node.val <= 10000
        Node.random is null or pointing to a node in the linked list.
        The number of nodes will not exceed 1000.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    在每个结点后面先复制出一个结点；然后将所有新结点的 random 域修改为老结点 random 指针的 next；
    最后将新结点的 next 修改。
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }

        Node *p = head, *q;
        while (p) {
            Node *node = new Node(p->val);
            node->next = p->next;
            p->next = node;

            p = p->next->next;
        }

        p = head;
        while (p) {
            q = p->next;
            q->random = p->random ? p->random->next : NULL;

            p = p->next->next;
        }

        p = head;
        q = head->next;
        Node *new_head = q;
        while (p) {
            p->next = q->next;
            q->next = p->next ? p->next->next : NULL;

            p = p->next;
            q = q->next;
        }

        return new_head;
    }
};

int main()
{
    Node tail(2);
    tail.random = &tail;
    Node head(1);
    head.next = &tail;
    head.random = &tail;

    Node *p = &head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;


    return 0;
}