/**
 * @author Mr Dk.
 * @version 2020.11.20
 */

/*
    Sort a linked list using insertion sort.

    A graphical example of insertion sort. The partial sorted
    list (black) initially contains only the first element in
    the list.
    With each iteration one element (red) is removed from the
    input data and inserted in-place into the sorted list.

    Algorithm of Insertion Sort:

    Insertion sort iterates, consuming one input element each
    repetition, and growing a sorted output list.
    At each iteration, insertion sort removes one element from
    the input data, finds the location it belongs within the
    sorted list, and inserts it there.
    It repeats until no input elements remain.

    Example 1:
        Input: 4->2->1->3
        Output: 1->2->3->4
        
    Example 2:
        Input: -1->5->3->4->0
        Output: -1->0->3->4->5

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/insertion-sort-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    链表实现排序的复杂点在于，需要记录被操作结点的前驱结点，以方便操作指针。
    程序中分配了一个伪头结点，作为头结点的前驱结点，方便操作。
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

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
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;

        ListNode *sorting_pre = head;
        ListNode *sorting = head->next;
        while (sorting) {
            ListNode *search_pre = fake_head;
            ListNode *search = fake_head->next;

            while (search != sorting) {
                if (sorting->val < search->val) {
                    ListNode *p = sorting; // sorting node

                    sorting = sorting->next; // prepare for the next loop
                    sorting_pre->next = sorting; // remove sorting node

                    p->next = search;
                    search_pre->next = p; // insert the sorting node

                    break;
                }

                // search for next insert position
                search = search->next;
                search_pre = search_pre->next;
            }

            // sorting node is bigger than all sorted node, try next.
            if (search == sorting) {
                sorting = sorting->next;
                sorting_pre = sorting_pre->next;
            }
        }

        head = fake_head->next;
        delete fake_head;
        return head;
    }
};

int main() {
    ListNode *n;
    ListNode *head;

    head = n = new ListNode(3);
    head = new ListNode(1);
    head->next = n;
    n = head;
    head = new ListNode(2);
    head->next = n;
    n = head;
    head = new ListNode(4);
    head->next = n;
    n = head;

    Solution s;
    n = s.insertionSortList(n);

    while (n) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;

    return 0;
}