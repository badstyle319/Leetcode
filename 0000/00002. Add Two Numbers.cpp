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
    ListNode* func(ListNode* l1, ListNode* l2, int &carry)
    {
        if(!l1 && !l2)
        {
            return carry?(new ListNode(carry)):NULL;
        }
        
        int sum = carry;
        if(l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        sum %= 10;
        
        ListNode *prev = new ListNode(sum);
        auto node = func(l1, l2, carry);
        prev->next = node;
        
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        // recursive
        int carry = 0;
        return func(l1, l2, carry);
        
//         // iterative
//         ListNode *ans = NULL, *it = NULL;
//         int carry = 0;
        
//         while(l1 || l2)
//         {
//             ListNode* newNode = new ListNode(carry);
//             if(l1)
//             {
//                 newNode->val += l1->val;
//                 l1 = l1->next;
//             }
//             if(l2)
//             {
//                 newNode->val += l2->val;
//                 l2 = l2->next;
//             }
//             carry = newNode->val / 10;
//             newNode->val %= 10;
//             if(!it)
//             {
//                 it = newNode;
//                 ans = it;
//             }
//             else
//             {
//                 it->next = newNode;
//                 it = it->next;
//             }
//         }
//         if(carry)
//         {
//             if(!it)
//             {
//                 it = new ListNode(carry);
//                 ans = it;
//             }
//             else
//             {
//                 it->next = new ListNode(carry);
//                 it = it->next;
//             }
//         }
        
//         return ans;
    }
};