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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return vector<double>();
        
        queue<TreeNode*> q;
        vector<double> ans;
        
        q.push(root);
        while(q.size() > 0)
        {
            int len = q.size();
            
            ans.push_back(0);
            for(int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                ans.back() += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.back() /= len;
        }
        return ans;
    }
};