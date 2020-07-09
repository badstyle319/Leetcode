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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
        if(!root)
            return v;
        
        v.push_back(vector<int>(1, root->val));
        auto left = levelOrder(root->left);
        auto right = levelOrder(root->right);
        vector<int> merge;
        int i;
        for(i = 0; i < left.size() && i < right.size(); i++)
        {
            vector<int> merge;
            merge.insert(merge.end(), left[i].begin(), left[i].end());
            merge.insert(merge.end(), right[i].begin(), right[i].end());
            v.push_back(merge);
        }
        for(; i < left.size(); i++)
            v.push_back(left[i]);
        for(; i < right.size(); i++)
            v.push_back(right[i]);
        
        return v;
    }
};