/**
 * @author Mr Dk.
 * @version 2021/03/26
 */

/*
    Given the head of a sorted linked list, delete all nodes that have
    duplicate numbers, leaving only distinct numbers from the original
    list. Return the linked list sorted as well. 

    Example 1:
        Input: head = [1,2,3,3,4,4,5]
        Output: [1,2,5]

    Example 2:
        Input: head = [1,1,1,2,3]
        Output: [2,3]

    Constraints:
        The number of nodes in the list is in the range [0, 300].
        -100 <= Node.val <= 100
        The list is guaranteed to be sorted in ascending order.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    由于被删除的只有重复结点，甚至可以不用维护伪头结点，直接遍历一次链表即可。
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head) {
            ListNode *p = head;
            while (p->next) {
                if (p->val == p->next->val) {
                    ListNode *q = p->next;
                    p->next = q->next;
                    delete q;
                } else {
                    p = p->next;
                }
            }
        }
        return head;
    }
};

void test(vector<int> &input, vector<int> &output) {
    Solution s;

    ListNode *head = NULL;
    for (int i = input.size() - 1; i >= 0; i--) {
        head = new ListNode(input[i], head);
    }

    head = s.deleteDuplicates(head);

    size_t i = 0;
    while (head) {
        ListNode *p = head->next;
        assert(output[i++] == head->val);
        delete head;
        head = p;
    }
}

int main()
{
    vector<int> input;
    vector<int> output;

    input = { 1,1,2 };
    output = { 1,2 };
    test(input, output);

    input = { 1,1,2,3,3 };
    output = { 1,2,3 };
    test(input, output);

    return 0;
}
