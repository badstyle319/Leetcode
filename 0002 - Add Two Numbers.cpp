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
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *ans = NULL, *it = NULL;
        int carry = 0;
        
        while(l1 || l2)
        {
            ListNode* newNode = new ListNode(carry);
            if(l1)
            {
                newNode->val += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                newNode->val += l2->val;
                l2 = l2->next;
            }
            carry = newNode->val / 10;
            newNode->val %= 10;
            if(!it)
            {
                it = newNode;
                ans = it;
            }
            else
            {
                it->next = newNode;
                it = it->next;
            }
        }
        if(carry)
        {
            if(!it)
            {
                it = new ListNode(carry);
                ans = it;
            }
            else
            {
                it->next = new ListNode(carry);
                it = it->next;
            }
        }
        
        return ans;
    }
};