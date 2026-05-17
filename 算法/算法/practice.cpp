class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* Ret = ret;
        int cnt = 0;
        while (l1 || l2 || cnt)
        {
            int tmp = 0;
            if (l1)
            {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                tmp += l2->val;
                l2 = l2->next;
            }
            tmp += cnt;
            cnt = 0;
            if (tmp > 9)
            {
                cnt = tmp / 10;
            }
            ret->next = new ListNode(tmp % 10);
            ret = ret->next;
        }
        return Ret->next;
    }
};