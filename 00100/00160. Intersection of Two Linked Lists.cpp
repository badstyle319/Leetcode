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
        ListNode *ta = headA, *tb = headB;
        while(ta != tb)
        {
            ta = ta?ta->next:headB;
            tb = tb?tb->next:headA;
        }
        return ta;
    }
};