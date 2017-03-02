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
    int ans=1e9;
    TreeNode *pre = NULL;
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return ans;
        
        getMinimumDifference(root->left);
        if(pre)
            ans = min(ans, abs(pre->val-root->val));
        pre = root;
        getMinimumDifference(root->right);
        return ans;
    }
};