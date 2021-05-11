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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* L = new ListNode();
        ListNode* pL = L;
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                L->next = l1;
                l1=l1->next;
            }
            else
            {
                L->next = l2;
                l2=l2->next;
            }
            L=L->next;
        }
        if(l1)
        {
            L->next = l1;
        }
        if(l2)
        {
            L->next = l2;
        }
        return pL->next;
    }
};
