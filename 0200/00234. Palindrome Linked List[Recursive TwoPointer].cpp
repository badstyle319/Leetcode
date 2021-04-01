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
    bool isPalindrome(ListNode* head) {
        auto slow = head;
        auto fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        auto mid = reverseNode(slow);
        
        while(mid)
        {
            if(mid->val != head->val)
                return false;
            
            head = head->next;
            mid = mid->next;
        }
        
        return true;
    }
    
    ListNode* reverseNode(ListNode* head)
    {
        if(!head || !head->next) return head;
        
        auto node = reverseNode(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return node;
    }
};