#define _CRT_SECURE_NO_WARNINGS 1
//typedef struct ListNode ListNode;
//struct ListNode* middleNode(struct ListNode* head) {
//    ListNode* show, * fast;
//    show = fast = head;
//    while (fast && fast->next)
//    {
//        show = show->next;
//        fast = fast->next->next;
//    }
//    return show;
//}
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    ListNode* newhead, * newtail;
//    newhead = newtail = NULL;
//    ListNode* pcur = head;
//    while (pcur)
//    {
//        if (pcur->val != val)
//        {
//            if (newhead == NULL)
//            {
//                newhead = newtail = pcur;
//            }
//            else
//            {
//                newtail->next = pcur;
//                newtail = newtail->next;
//            }
//        }
//        pcur = pcur->next;
//    }
//    if (newtail != NULL)
//    {
//        newtail->next = NULL;
//    }
//    return newhead;
//}

//typedef struct ListNode  ListNode;
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//
//    ListNode* newhead, * newtail;
//    newhead = newtail = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* l1 = list1;
//    ListNode* l2 = list2;
//    while (l1 && l2)
//    {
//        if (l1->val < l2->val)
//        {
//            newtail->next = l1;
//            l1 = l1->next;
//            newtail = newtail->next;
//        }
//        else
//        {
//            newtail->next = l2;
//            l2 = l2->next;
//            newtail = newtail->next;
//        }
//    }
//    if (l2)
//        newtail->next = l2;
//    if (l1)
//        newtail->next = l1;
//    ListNode* rethead = newhead->next;
//    free(newhead);
//    newhead = NULL;
//    return rethead;
//}
//
//
//
//
//class PalindromeList {
//public:
//    ListNode* middlenode(ListNode* A)
//    {
//        ListNode* slow, * fast;
//        slow = fast = A;
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//    ListNode* reverselist(ListNode* A)
//    {
//        if (A == NULL)
//            return NULL;
//        ListNode* n1, * n2, * n3;
//        n1 = NULL;
//        n2 = A;
//        n3 = A->next;
//        while (n2)
//        {
//            n2->next = n1;
//            n1 = n2;
//            n2 = n3;
//            if (n3)
//                n3 = n3->next;
//        }
//        return n1;
//    }
//    bool chkPalindrome(ListNode* A) {
//        // write code here
//        ListNode* MA = middlenode(A);
//        ListNode* RA = reverselist(MA);
//
//        while (RA)
//        {
//            if (RA->val != A->val)
//            {
//                return false;
//            }
//            RA = RA->next;
//            A = A->next;
//        }
//        return true;
//    }
//};