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
    pair<ListNode*,ListNode*>reverseK(ListNode*head,ListNode*tail)
    {
        ListNode*prev = tail->next,*curr = head;
        while(prev!=tail)
        {
            ListNode*temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return {tail,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pHead = new ListNode(0,head);
        ListNode* prev = pHead;
        while(head)
        {
            ListNode* tail = head;
            int count = 1;
            while(tail&&count<k)
            {
                tail=tail->next;
                count+=1;
            }
            if(count<k||!tail)
            {
                break;
            }
            pair<ListNode*,ListNode*>result = reverseK(head,tail);
            prev->next = result.first;
            prev = result.second;
            head = prev->next;
        }
        return pHead->next;
    }
};
