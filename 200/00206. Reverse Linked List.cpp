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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        // iterative
//         ListNode *p = head;
//         ListNode *q = head->next;
//         ListNode *r = head->next->next;
        
//         p->next = NULL;
//         while(r)
//         {
//             q->next = p;
//             p = q;
//             q = r;
//             r = r->next;
//         }
//         q->next = p;
        
//         return q;
        
        // recursive
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
};