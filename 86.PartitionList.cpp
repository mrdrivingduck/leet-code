/**
 * @author Mr Dk.
 * @version 2021/01/03
 */

/*
    Given a linked list and a value x, partition it such that all nodes
    less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each
    of the two partitions.

    Example:
        Input: head = 1->4->3->2->5->2, x = 3
        Output: 1->2->2->4->3->5

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/partition-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    设计两个子链表头结点，从原链表上依次拆下结点放入子链表，然后将两个
    子链表合并即可。
 */

#include <cassert>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *head_smaller = new ListNode(-1);
        ListNode *head_larger = new ListNode(-1);
        ListNode *smaller_tail = head_smaller;
        ListNode *larger_tail = head_larger;

        ListNode *p = head;
        while (p != NULL) {
            if (p->val < x) {
                smaller_tail->next = p;
                smaller_tail = smaller_tail->next;
            } else {
                larger_tail->next = p;
                larger_tail = larger_tail->next;
            }

            p = p->next;
        }

        // merge
        larger_tail->next = NULL;
        smaller_tail->next = head_larger->next;

        p = head_smaller->next;
        delete head_smaller;
        delete head_larger;
        return p;
    }
};

int main()
{
    Solution s;
    ListNode *head;

    // 1->4->3->2->5->2
    head = new ListNode(2);
    head = new ListNode(5, head);
    head = new ListNode(2, head);
    head = new ListNode(3, head);
    head = new ListNode(4, head);
    head = new ListNode(1, head);
    head = s.partition(head, 3);

    // 1->2->2->4->3->5
    assert(1 == head->val);
    head = head->next;
    assert(2 == head->val);
    head = head->next;
    assert(2 == head->val);
    head = head->next;
    assert(4 == head->val);
    head = head->next;
    assert(3 == head->val);
    head = head->next;
    assert(5 == head->val);
    head = head->next;
    assert(NULL == head);

    return 0;
}
