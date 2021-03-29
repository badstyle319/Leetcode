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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        stack<TreeNode*> st{{root}};
        vector<int> ans;
        int i = 0;
        
        while(!st.empty())
        {
            TreeNode *cur = st.top(); st.pop();
            if(cur->val != voyage[i])
                return {-1};

            i++;
            if(cur->left && cur->left->val != voyage[i])
            {
                swap(cur->left, cur->right);
                ans.push_back(cur->val);
            }
            if(cur->right)
                st.push(cur->right);
            if(cur->left)
                st.push(cur->left);
        }
        
        return ans;
    }
};