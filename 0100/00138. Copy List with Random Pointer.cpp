/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        unordered_map<Node*, Node*> mp;
        Node *ans = new Node(head->val);
        Node *dst = ans, *org;
        
        mp[head] = ans;
        org = head;
        while(org->next)
        {
            mp[org->next] = new Node(org->next->val);
            dst->next = mp[org->next];

            org = org->next;
            dst = dst->next;
        }
        
        org = head;
        dst = ans;
        while(org)
        {
            dst->random = org->random?mp[org->random]:NULL;
            
            org = org->next;
            dst = dst->next;
        }
        
        return ans;
    }
};