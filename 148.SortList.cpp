/**
 * @author Mr Dk.
 * @version 2020.11.21
 */

/*
    Given the head of a linked list, return the list after sorting
    it in ascending order.

    Follow up: Can you sort the linked list in O(n logn) time and
    O(1) memory (i.e. constant space)?

    Example 1:
        Input: head = [4,2,1,3]
        Output: [1,2,3,4]

    Example 2:
        Input: head = [-1,5,3,4,0]
        Output: [-1,0,3,4,5]

    Example 3:
        Input: head = []
        Output: []

    Constraints:
        The number of nodes in the list is in the range [0, 5 * 104].
        -105 <= Node.val <= 105

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/sort-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    既然要获得 O(nlog(n)) 的时间复杂度，只可能使用快速排序、堆排序或归并排序。
    考虑到题目是链表实现，所以只能使用归并排序。归并排序分为自顶向下和自底向上，
    考虑到题目的空间复杂度要求 (O(1))，因此使用自底向上的归并排序。

    自顶向下的思路：将链表拆分为两个子链表，分别进行归并排序，然后将两个有序的
    子链表归并为一个有序链表。由于需要用到递归，因此有隐式空间复杂度。
    自底向上的思路：将链表拆分为 n 个长度为 1 的子链表，每次将两个链表合并为
    一个有序的链表，得到 n/2 (取上整) 个长度翻倍的子链表。依此类推，直到合并
    为一个有序的链表。
 */

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
    ListNode* sortList(ListNode* head) {
        // return merge_top_down(head);
        return merge_bottom_up(head);
    }

    ListNode *merge_bottom_up(ListNode *head) {
        if (!head) {
            return head;
        }

        int length = 0;
        ListNode *worker = head;
        while (worker) {
            length++;
            worker = worker->next;
        }

        ListNode dummy_head;
        dummy_head.next = head;
        int step_len = 1;

        while (step_len < length) {
            int count = 0;
            ListNode *sub_1 = head, *sub_1_tail, *sub_2, *sub_2_tail;
            ListNode *worker = head;
            ListNode *pre = &dummy_head;

            while (sub_1) {
                count = 0;
                worker = sub_1;
                while (count < step_len && worker) {
                    count++;
                    sub_1_tail = worker;
                    worker = worker->next;
                }
                sub_2 = worker;
                if (!sub_2) {
                    break;
                }

                sub_1_tail->next = NULL; // cut sequence 1

                count = 0;
                while (count < step_len && worker) {
                    count++;
                    sub_2_tail = worker;
                    worker = worker->next;
                }
                sub_2_tail->next = NULL;  // cut sequence 2

                // worker is the next

                // merge
                ListNode *tail = pre;
                while (sub_1 && sub_2) {
                    if (sub_1->val < sub_2->val) {
                        tail->next = sub_1;
                        sub_1 = sub_1->next;
                    } else {
                        tail->next = sub_2;
                        sub_2 = sub_2->next;
                    }
                    tail = tail->next;
                }
                while (sub_1) {
                    tail->next = sub_1;
                    sub_1 = sub_1->next;
                    tail = tail->next;
                }
                while (sub_2) {
                    tail->next = sub_2;
                    sub_2 = sub_2->next;
                    tail = tail->next;
                }

                // prepare for the next two sub sequences
                sub_1 = worker;
                tail->next = worker;
                pre = tail;   
            }

            // next iteration step
            head = dummy_head.next;
            step_len <<= 1;
        }

        return dummy_head.next;
    }

    ListNode *merge_top_down(ListNode *head) {
        if (!head) {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        bool move_slow = false;
        while (fast->next) {
            if (move_slow) {
                slow = slow->next;
                move_slow = false;
            } else {
                move_slow = true;
            }
            fast = fast->next;
        }

        if (fast == slow) {
            return head;
        }

        fast = slow->next;
        slow->next = NULL;

        // sub list 1: head
        // sub list 2: fast
        head = merge_top_down(head);
        fast = merge_top_down(fast);

        // merge two sublist
        ListNode *new_head = new ListNode(); // dummy head
        slow = new_head; // slow pointer re-used as tail
        while (head && fast) {
            if (head->val < fast->val) {
                slow->next = head;
                head = head->next;
            } else {
                slow->next = fast;
                fast = fast->next;
            }
            slow = slow->next;
        }
        if (head) {
            slow->next = head;
        }
        if (fast) {
            slow->next = fast;
        }

        slow = new_head->next; // slow re-used as new head
        delete new_head;
        return slow;
    }
};

int main()
{
    Solution s;
    ListNode *head;

    head = new ListNode(3);
    head = new ListNode(1, head);
    head = new ListNode(2, head);
    head = new ListNode(4, head);
    head = s.sortList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    head = new ListNode(0);
    head = new ListNode(4, head);
    head = new ListNode(3, head);
    head = new ListNode(5, head);
    head = new ListNode(-1, head);
    head = s.sortList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}