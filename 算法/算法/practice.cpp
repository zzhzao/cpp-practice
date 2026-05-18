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
class Solution {
    struct cmp
    {
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;

        for (auto e : lists)
        {
            if (e)
                heap.push(e);
        }
        ListNode* head = new ListNode(0);
        ListNode* prev = head;
        while (!heap.empty())
        {
            ListNode* top = heap.top();
            heap.pop();
            prev->next = top;
            prev = top;
            if (top->next)
                heap.push(top->next);
        }
        prev = head->next;
        delete head;
        return prev;
    }
};