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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        
        ListNode* pa = headA;
        ListNode* pb = headB;
        
        while(pa)
        {
            s.insert(pa);
            pa = pa->next;
        }
        
        ListNode *ans = NULL;
        while(pb)
        {
            if(s.count(pb))
            {
                if(!ans)
                    ans = pb;
            }
            else
            {
                ans = NULL;
            }
            pb = pb->next;
        }
        
        return ans;
    }
};