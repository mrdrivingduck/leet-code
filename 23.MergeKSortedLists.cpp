/**
 * @author Mr DK.
 * @version 2021/03/26
 */

/*
    You are given an array of k linked-lists lists, each linked-list is
    sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list and return it.

    Example 1:
        Input: lists = [[1,4,5],[1,3,4],[2,6]]
        Output: [1,1,2,3,4,4,5,6]
        Explanation: The linked-lists are:
            [
                1->4->5,
                1->3->4,
                2->6
            ]
        merging them into one sorted list:
        1->1->2->3->4->4->5->6

    Example 2:
        Input: lists = []
        Output: []

    Example 3:
        Input: lists = [[]]
        Output: []

    Constraints:
        k == lists.length
        0 <= k <= 10^4
        0 <= lists[i].length <= 500
        -10^4 <= lists[i][j] <= 10^4
        lists[i] is sorted in ascending order.
        The sum of lists[i].length won't exceed 10^4.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    维护一个优先队列，保存当前所有链表中的最小值，通过优先队列不断选出
    所有链表中的最小值，并添加到合并后的链表尾部，同时将该最小值的下一个
    结点加入优先队列中，直到优先队列为空。
*/

#include <cassert>

#include <iostream>
#include <vector>
#include <queue>
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

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

struct comp {
    bool operator()(ListNode* &p1, ListNode* &p2) {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> queue;

        for (size_t i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                queue.push(lists[i]);
            }
        }

        ListNode dummp_head(-1, NULL);
        ListNode *tail = &dummp_head;

        while (!queue.empty()) {
            ListNode *smallest = queue.top();
            queue.pop();
            if (smallest->next) {
                queue.push(smallest->next);
                smallest->next = NULL;
            }

            tail->next = smallest;
            tail = tail->next;
        }

        return dummp_head.next;
    }
};

void assert_linked_list(vector<vector<int>> &lists, vector<int> &output) {
    vector<ListNode*> all_lists;
    for (size_t i = 0; i < lists.size(); i++) {
        ListNode *head = NULL;
        for (int j = lists[i].size() - 1; j >= 0; j--) {
            head = new ListNode(lists[i][j], head);
        }
        all_lists.push_back(head);
    }

    Solution s;
    ListNode *merged = s.mergeKLists(all_lists);

    for (size_t i = 0; i < output.size(); i++) {
        assert(output[i] == merged->val);
        ListNode *temp = merged;
        merged = merged->next;
        delete temp;
    }
}

int main()
{
    vector<vector<int>> lists;
    vector<int> output;

    lists = {
        { 1,4,5 },
        { 1,3,4 },
        { 2,6 }
    };
    output = { 1,1,2,3,4,4,5,6 };
    assert_linked_list(lists, output);

    lists = {  };
    output = {  };
    assert_linked_list(lists, output);

    lists = {
        {  }
    };
    output = {  };
    assert_linked_list(lists, output);

    return 0;
}
