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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        int len = 0;
        while(slow)
        {
            len++;
            slow = slow->next;
        }
        k %= len;
        
        slow = head;
        while(k--)
        {
            fast = fast->next;
        }
        
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }
};