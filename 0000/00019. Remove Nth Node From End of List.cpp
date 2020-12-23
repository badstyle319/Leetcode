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
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = dummy, *second = dummy;
        
        while(n--)
            second = second->next;
        
        while(second->next)
        {
            first = first->next;
            second = second->next;
        }
        // cout << first->val << " " << second->val << endl;
            
        ListNode *temp = first->next;
        first->next = temp->next;
        delete temp;
        
        return dummy->next;
    }
};