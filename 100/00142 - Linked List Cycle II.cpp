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
        
//         set<ListNode*> s;
        
//         ListNode* cur = head;
//         while(cur && !s.count(cur))
//         {
//             s.insert(cur);
//             cur = cur->next;
//         }
        
//         return cur;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        
        if(!fast || !fast->next)
            return NULL;
        
        // cout << fast->val << endl;
        
        // why this process can find the cycle start?
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};