/**
 * @author Mr Dk.
 * @version 2021/03/18
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
    遍历一次链表，记录好逆置区间之前和之后的结点，以方便重新链接；
    将逆置区间的链表逆置后，重新链接到原链表上。
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy_head = new ListNode(-1, head);

        ListNode *p = dummy_head;
        ListNode *reverse_head;
        ListNode *relink_tail;
        ListNode *relink_next;
        for (int i = 0; i <= right; i++) {
            if (i == left - 1) {
                relink_tail = p;
            }
            if (i == left) {
                reverse_head = p;
            }
            if (i == right) {
                relink_next = p->next;
                p->next = NULL;
            }
            p = p->next;
        }

        ListNode *reverse_dummy = new ListNode(-1);
        ListNode *reverse_tail = reverse_head;
        while (reverse_head) {
            ListNode *temp = reverse_head;
            reverse_head = reverse_head->next;

            temp->next = reverse_dummy->next;
            reverse_dummy->next = temp;
        }

        reverse_tail->next = relink_next;
        relink_tail->next = reverse_dummy->next;

        ListNode *new_head = dummy_head->next;
        delete dummy_head;
        delete reverse_dummy;
        return new_head;
    }
};

void assert_result(vector<int> &nums, vector<int> &expect, int left, int right) {
    Solution s;
    ListNode *head = NULL;

    // 1->2->3->4->5
    for (int i = nums.size() - 1; i >= 0; i--) {
        head = new ListNode(nums[i], head);
    }

    head = s.reverseBetween(head, left, right);

    ListNode *iter = head;
    for (size_t i = 0; i < expect.size(); i++) {
        assert(expect[i] == iter->val);
        iter = iter->next;
    }
    assert(NULL == iter);

    iter = head;
    while (head) {
        iter = head;
        head = head->next;
        delete iter;
    }
}

int main()
{
    vector<int> nums;
    vector<int> expect;

    nums = { 1,2,3,4,5 };
    expect = { 1,4,3,2,5 };
    assert_result(nums, expect, 2, 4);

    nums = { 5 };
    expect = { 5 };
    assert_result(nums, expect, 1, 1);

    return 0;
}
