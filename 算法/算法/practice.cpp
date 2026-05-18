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
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return;
        }
        ListNode* slow = head, * fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = new ListNode(0);
        ListNode* cur = slow->next;
        slow->next = nullptr;
        ListNode* next = nullptr;
        while (cur)
        {
            next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = next;
        }

        ListNode* cur1 = head, * cur2 = head2->next;
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;

        while (cur1 && cur2)
        {
            next1 = cur1->next;
            cur1->next = cur2;
            next2 = cur2->next;
            cur2->next = next1;
            cur1 = next1;

            cur2 = next2;
        }

        delete head2;
    }
};