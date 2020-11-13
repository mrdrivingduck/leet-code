/**
 * @author Mr Dk.
 * @version 2020.11.13
 */

/*
    Given a singly linked list, group all odd nodes together followed by
    the even nodes. Please note here we are talking about the node number
    and not the value in the nodes.

    You should try to do it in place. The program should run in O(1) space
    complexity and O(nodes) time complexity.

    Example 1:
        Input: 1->2->3->4->5->NULL
        Output: 1->3->5->2->4->NULL

    Example 2:
        Input: 2->1->3->5->6->4->7->NULL
        Output: 2->3->6->7->1->5->4->NULL
     

    Constraints:
        The relative order inside both the even and odd groups should remain
        as it was in the input.
        The first node is considered odd, the second node even and so on ...
        The length of the linked list is between [0, 10^4].

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/odd-even-linked-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    要求空间复杂度为 O(1) 的原地算法。两个奇偶指针交替后移，直到两者的 next 指针都为空。
    保证奇指针停在最后一个结点上。最后将奇偶链表串在一起。
 */

#include <iostream>
using std::cout;
using std::endl;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = head, *q = head->next;
        ListNode *odd_head = q;

        while (q && q->next) {
            p->next = q->next;
            p = p->next;
            q->next = p->next;
            q = q->next;
        }

        p->next = odd_head;

        return head;
    }
};

int main() {

    Solution s;
    ListNode *p = new ListNode(5);
    p = new ListNode(4, p);
    p = new ListNode(3, p);
    p = new ListNode(2, p);
    p = new ListNode(1, p);
    p = s.oddEvenList(p);

    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    p = new ListNode(4);
    p = new ListNode(3, p);
    p = new ListNode(2, p);
    p = new ListNode(1, p);

    p = s.oddEvenList(p);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
