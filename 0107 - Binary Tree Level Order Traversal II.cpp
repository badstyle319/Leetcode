/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void traverse(TreeNode* root, vector<vector<int>> &ans, int level){
        if(!root)
            return;
        
        if(ans.size()==level)
            ans.insert(ans.begin(), vector<int>());
        ans[ans.size()-level-1].push_back(root->val);
        traverse(root->left, ans, level+1);
        traverse(root->right, ans, level+1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root, ans, 0);
        return ans;
    }
};