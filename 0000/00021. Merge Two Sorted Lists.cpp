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
        
        if(!l1 && !l2)
            return NULL;
        
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        // // recursive
        // if(l1->val <= l2->val)
        // {
        //     auto merge = mergeTwoLists(l1->next, l2);
        //     l1->next = merge;
        //     return l1;
        // }
        // else
        // {
        //     auto merge = mergeTwoLists(l1, l2->next);
        //     l2->next = merge;
        //     return l2;
        // }
        
        // iterative
        ListNode *head = NULL;
        ListNode *pL = l1, *pR = l2, *pH = NULL;
        if(pL->val <= pR->val)
        {
            head = pL;
            pL = pL->next;
        }
        else
        {
            head = pR;
            pR = pR->next;
        }
        pH = head;
        while(pL && pR)
        {
            if(pL->val <= pR->val)
            {
                pH->next = pL;
                pL = pL->next;
            }
            else
            {
                pH->next = pR;
                pR = pR->next;
            }
            pH = pH->next;
        }
        if(pL)
            pH->next = pL;
        if(pR)
            pH->next = pR;
        
        return head;
    }
};