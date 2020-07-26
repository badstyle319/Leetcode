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
    TreeNode* dfs(vector<int> &postorder, int L, int R)
    {
        if(L > R)
            return NULL;
        
        int val = postorder[pos--];
        int mid = mp[val];

        TreeNode* node = new TreeNode(val);
        
        node->right = dfs(postorder, mid + 1, R);
        node->left = dfs(postorder, L, mid - 1);
        
        return node;
    }
    
    void print(vector<int> &v)
    {
        for(auto val:v)
            cout << " " << val;
        cout << endl;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // int len = postorder.size();
    
        // if(len == 0)
            // return NULL;
        
        // TreeNode *root = new TreeNode(postorder.back());
        
        // if(len == 1)
            // return root;
        
        // auto it = find(inorder.begin(), inorder.end(), postorder.back());
        // int lenL = it - inorder.begin();
        // vector<int> inL(inorder.begin(), it);
        // vector<int> inR(it + 1, inorder.end());
        // vector<int> poL(postorder.begin(), postorder.begin() + lenL);
        // vector<int> poR(postorder.begin() + lenL, postorder.end() - 1);
        
        // root->left = buildTree(inL, poL);
        // root->right = buildTree(inR, poR);
        
        // return root;
        int len = (int)inorder.size();
        pos = len - 1;
        
        mp.clear();
        for(int i = 0; i < len; i++)
            mp[inorder[i]] = i;
        
        return dfs(postorder, 0, len - 1);
    }
};