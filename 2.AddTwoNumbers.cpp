/*
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order and each of their nodes contain a single digit.
    Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, 
    except the number 0 itself.

    Example:

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/add-two-numbers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    @author Mr Dk.
    @2019/08/03, Nanjing, Jiangsu, China

    依次遍历两个链表，并维护进位
    如果有一个链表已经到达尽头
    则遍历另一个链表直到结尾

    默认结点数值为 0 
    不要忘记最后一次的进位
        如果链表遍历完毕，还存在进位，还需要再开辟一个结点
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // default node
        ListNode* h = new ListNode(0);
        ListNode* curr = h; // pointing to the current node
        ListNode* last = curr; // pointing to the last complete node
        int cf = 0; // carring flag

        // two linklists are not at the end
        while (l1 && l2) {
            if (!curr) {
                // the new node has not been allocated
                last -> next = new ListNode(l1 -> val + l2 -> val + cf);
                curr = last -> next;
            } else {
                // the new node has been allocated
                // first time only
                curr -> val = l1 -> val + l2 -> val + cf;
            }

            // carring
            if (curr -> val > 9) {
                (curr -> val) -= 10;
                cf = 1;
            } else {
                cf = 0;
            }

            // to the next node
            l1 = l1 -> next;
            l2 = l2 -> next;
            last = curr;
            curr = curr -> next;
        }

        // l2 came to the end
        while (l1) {
            if (!curr) {
                // the new node has not been allocated
                last -> next = new ListNode(l1 -> val + cf);
                curr = last -> next;
            } else {
                // the new node has been allocated
                curr -> val = l1 -> val + cf;
            }

            // carring
            if (curr -> val > 9) {
                (curr -> val) -= 10;
                cf = 1;
            } else {
                cf = 0;
            }

            // next node in l1
            l1 = l1 -> next;
            last = curr;
            curr = curr -> next; 
        }

        // l1 came to the end
        while (l2) {
            if (!curr) {
                // the new node has not been allocated
                last -> next = new ListNode(l2 -> val + cf);
                curr = last -> next;
            } else {
                // the new node has been allocated
                curr -> val = l2 -> val + cf;
            }

            // carring
            if (curr -> val > 9) {
                (curr -> val) -= 10;
                cf = 1;
            } else {
                cf = 0;
            }

            // next node in l2
            l2 = l2 -> next;
            last = curr;
            curr = curr -> next; 
        }

        // 5 + 5 = 10 ?
        if (cf > 0) {
            last -> next = new ListNode(cf);
        }

        return h;
    }

    void destroy(ListNode *h) {
        while (h) {
            ListNode *next = h -> next;
            delete h;
            h = next;
        }
    }
};

int main() {

    ListNode l11(0);
    ListNode l12(4);
    ListNode l13(3);

    ListNode l21(0);
    ListNode l22(6);
    ListNode l23(4);

    l11.next = &l12;
    l12.next = &l13;

    l21.next = &l22;
    l22.next = &l23;

    Solution solution;
    ListNode* res = solution.addTwoNumbers(&l11, &l21);
    while (res) {
        cout << res -> val << endl;
        res = res -> next;
    }

    solution.destroy(res);

    return 0;
}
