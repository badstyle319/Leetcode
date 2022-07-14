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
    void print(ListNode* head)
    {
        ListNode* cur = head;
        while(cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* oddTail = head;
        ListNode* evenStart = head->next;
        ListNode* evenEnd = head->next;
        ListNode* oddNode = head->next->next;
        while(oddNode)
        {
            // print(head);
            evenEnd->next = oddNode->next;
            evenEnd = evenEnd->next;
            oddNode->next = evenStart;
            oddTail->next = oddNode;
            
            oddNode = evenEnd?evenEnd->next:NULL;
            oddTail = oddTail->next;
        }
        
        return head;
    }
};