class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pHead = new ListNode(0,head);
        ListNode *fast = head,*slow = pHead;
        for(int i = 0;i<n;++i)
        {
            fast = fast->next;
        }
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode *ret = pHead->next;
        delete(pHead);
        return ret;
    }
};
