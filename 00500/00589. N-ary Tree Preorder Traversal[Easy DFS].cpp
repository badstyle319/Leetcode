/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void dfs(vector<int> &ans, Node* node)
    {
        if(!node)
            return;
        
        ans.push_back(node->val);
        for(auto *sub : node->children)
        {
            dfs(ans, sub);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        
        dfs(ans, root);
        
        return ans;
    }
};