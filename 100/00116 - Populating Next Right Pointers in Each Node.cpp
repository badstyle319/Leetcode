/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    vector<vector<Node*>> v;
    void bfs(Node* node, int level)
    {
        if(!node)
            return;
        
        if(v.size() == level)
            v.push_back(vector<Node*>());
        v[level].push_back(node);
        
        bfs(node->left, level + 1);
        bfs(node->right, level + 1);
    }
public:
    Node* connect(Node* root) {
        v.clear();
        
        bfs(root, 0);
        for(auto v1:v)
        {
            for(int i = 1; i < v1.size(); i++)
                v1[i-1]->next = v1[i];
        }
        
        return root;
    }
};