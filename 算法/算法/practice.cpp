class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* Cur = head;
        if (head == nullptr)
        {
            return head;
        }
        ListNode* Next = head->next;
        if (Next == nullptr)
        {
            return head;
        }
        ListNode* ret = Next;
        ListNode* prev = nullptr;
        while (Cur && Next)
        {
            Cur->next = Next->next;
            Next->next = Cur;
            if (prev != nullptr)
                prev->next = Next;
            prev = Cur;

            Cur = Cur->next;
            if (Cur != nullptr)
                Next = Cur->next;
        }
        return ret;
    }
};