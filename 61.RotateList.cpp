/**
 * @author Mr Dk.
 * @version 2021/03/27
 */

/*
    Given the head of a linked list, rotate the list to the right by k places.

    Example 1:
        Input: head = [1,2,3,4,5], k = 2
        Output: [4,5,1,2,3]

    Example 2:
        Input: head = [0,1,2], k = 4
        Output: [2,0,1]

    Constraints:
        The number of nodes in the list is in the range [0, 500].
        -100 <= Node.val <= 100
        0 <= k <= 2 * 109

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/rotate-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
    统计链表的长度，并对旋转次数取模，防止重复的旋转。使用快慢指针找到要旋转
    的区间的前一个结点和尾结点，将这段区间从链表上摘下来，插入到链表头部。
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        ListNode dummy_head(-1, head);
        ListNode *p = head;
        ListNode *prev;

        int length = 0;
        while (p) {
            length++;
            p = p->next;
        }
        if (length) {
            k %= length;
        }

        prev = &dummy_head;
        p = &dummy_head;
        for (int i = 0; i < k; i++) {
            prev = prev->next;
        }

        while (prev->next) {
            prev = prev->next;
            p = p->next;
        }

        prev->next = dummy_head.next;
        dummy_head.next = p->next;
        p->next = NULL;

        return dummy_head.next;
    }
};

void assert_linked_list(vector<int> &input, vector<int> &output, int k) {
    ListNode *head = NULL;
    for (int i = input.size() - 1; i >= 0; i--) {
        head = new ListNode(input[i], head);
    }

    Solution s;
    head = s.rotateRight(head, k);

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
    output = { 4,5,1,2,3 };
    assert_linked_list(input, output, 2);

    input = { 0,1,2 };
    output = { 2,0,1 };
    assert_linked_list(input, output, 4);

    return 0;
}
