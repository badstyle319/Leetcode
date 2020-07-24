/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        
        set<ListNode*> s;
        
        ListNode* cur = head;
        while(cur && !s.count(cur))
        {
            s.insert(cur);
            cur = cur->next;
        }
        
        return cur;
    }
};