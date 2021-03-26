/**
 * @author Mr Dk.
 * @version 2021/03/26
 */

/*
    Given the head of a linked list, remove the nth node from the end of
    the list and return its head.

    Follow up: Could you do this in one pass?

    Example 1:
        Input: head = [1,2,3,4,5], n = 2
        Output: [1,2,3,5]

    Example 2:
        Input: head = [1], n = 1
        Output: []

    Example 3:
        Input: head = [1,2], n = 1
        Output: [1]

    Constraints:
        The number of nodes in the list is sz.
        1 <= sz <= 30
        0 <= Node.val <= 100
        1 <= n <= sz

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    同时维护两个快慢指针，中间距离为 n。当快指针走到链表尾部时，慢指针指向将被删除的
    结点的前一个结点，从而便于删除。
*/

#include <cassert>

#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy_head(-1, head);
        ListNode *tail = &dummy_head;
        ListNode *pre = &dummy_head;

        for (int i = 0; i < n; i++) {
            tail = tail->next;
        }

        while (tail->next) {
            tail = tail->next;
            pre = pre->next;
        }

        tail = pre->next;
        pre->next = tail->next;
        delete tail;

        return dummy_head.next;
    }
};

void assert_linked_list(vector<int> &input, vector<int> &output, int n) {
    ListNode *head = NULL;
    for (int i = input.size() - 1; i >= 0; i--) {
        head = new ListNode(input[i], head);
    }

    Solution s;
    head = s.removeNthFromEnd(head, n);

    for (size_t i = 0; i < output.size(); i++) {
        assert(output[i] == head->val);
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    vector<int> input;
    vector<int> output;

    input = { 1,2,3,4,5 };
    output = { 1,2,3,5 };
    assert_linked_list(input, output, 2);

    input = { 1 };
    output = {  };
    assert_linked_list(input, output, 1);

    input = { 1,2 };
    output = { 1 };
    assert_linked_list(input, output, 1);

    return 0;
}
