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
    unordered_map<int, int> mp;
    int pos;
    
    TreeNode* dfs(vector<int> &pre, int L, int R)
    {
        if(L > R)
            return NULL;
        
        int val = pre[pos++];
        int mid = mp[val];
        
        TreeNode* node = new TreeNode(val);
        node->left = dfs(pre, L, mid - 1);
        node->right = dfs(pre, mid + 1, R);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        pos = 0;
        
        mp.clear();
        for(int i = 0; i < len; i++)
            mp[inorder[i]] = i;
        
        return dfs(preorder, 0, len - 1);
    }
};