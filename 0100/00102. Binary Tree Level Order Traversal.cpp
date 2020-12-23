/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void traverse(TreeNode* root, vector<vector<int>> &v, int level)
    {
        if(!root)
            return;
        
        if(v.size() == level)
            v.push_back(vector<int>());
        v[level].push_back(root->val);
        traverse(root->left, v, level+1);
        traverse(root->right, v, level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
        traverse(root, v, 0);
        
        return v;
    }
};