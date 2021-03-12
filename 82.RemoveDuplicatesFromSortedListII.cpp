/**
 * @author Mr Dk.
 * @version 2021/03/12
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
    维护一个指针，记录当前探测结点的前一个结点 (便于移除结点)。
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
        ListNode *table = new ListNode(-1, head);
        ListNode *pre = table;

        while (pre) {
            if (pre->next) {
                ListNode *current = pre->next;
                ListNode *diff = current->next;
                bool remove_current = false;
                while (diff) {
                    if (diff->val == current->val) {
                        current->next = diff->next;
                        delete diff;
                        diff = current->next;
                        remove_current = true;
                    } else {
                        break;
                    }
                }
                if (remove_current) {
                    pre->next = current->next;
                    delete current;
                } else {
                    pre = pre->next;
                }
            } else {
                pre = pre->next;
            }
        }

        pre = table->next;
        delete table;
        return pre;
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

    input = { 1,2,3,3,4,4,5 };
    output = { 1,2,5 };
    test(input, output);

    input = { 1,1,2,3,3,4,4,5 };
    output = { 2,5 };
    test(input, output);

    return 0;
}
