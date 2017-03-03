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
    unordered_map<int,int> mp;
    int maxValue;
    void dfs(TreeNode* root){
        if(!root)
            return;
        mp[root->val]++;
        maxValue=max(maxValue, mp[root->val]);
        dfs(root->left);
        dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        maxValue = 0;
        
        dfs(root);
        for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
            if(it->second==maxValue)
                ans.push_back(it->first);
        return ans;
    }
};