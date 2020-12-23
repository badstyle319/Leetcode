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
        if(!head)
            return true;
        
        deque<int> d;
        
        ListNode* cur = head;
        while(cur)
        {
            d.push_back(cur->val);
            cur = cur->next;
        }
        
        while(d.size() > 0)
        {
            if(d.size() == 1)
                return true;
            
            if(d.front() != d.back())
                return false;
            
            d.pop_front();
            d.pop_back();
        }
        
        return true;
    }
};