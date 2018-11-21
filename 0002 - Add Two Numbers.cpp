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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rv = new ListNode(0);
        ListNode *current = rv;
        int carry = 0, temp=0;
        
        for(;l1 || l2;){
            if(l1 && l2){
                carry = temp = l1->val + l2->val + carry;
                current->next = new ListNode(temp%10);
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1){
                carry = temp = l1->val + carry;
                current->next = new ListNode(temp%10);
                l1 = l1->next;
            }else if(l2){
                carry = temp = l2->val + carry;
                current->next = new ListNode(temp%10);
                l2 = l2->next;
            }
            carry /= 10;
            
            current = current->next;
        }
        if(carry)
            current->next = new ListNode(carry);
        
        return rv->next;
    }
};