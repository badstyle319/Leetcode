/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        Node *cur = head;
        
        while(cur)
        {
            if(cur->child)
            {
                if(cur->next)
                    s.push(cur->next);
                
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = NULL;
            }
            if(!cur->next)
                break;
            
            cur = cur->next;
        }
        
        while(s.size() > 0)
        {
            cur->next = s.top();
            s.top()->prev = cur;
            s.pop();
            while(cur->next)
                cur = cur->next;
        }
        
        return head;
    }
};