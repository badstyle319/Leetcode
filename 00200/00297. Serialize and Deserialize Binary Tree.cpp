/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        
        string ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0)
        {
            TreeNode* node = q.front(); q.pop();
            ans += node?to_string(node->val)+",":"#";
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        auto pos = ans.find_last_not_of("#");
        if(pos != string::npos)
            ans.erase(pos+1);
        
        return ans;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0)
            return NULL;
        
        TreeNode* root;
        queue<TreeNode*> q;
        bool bLeft = true;
        
        string::size_type sz;
        root = new TreeNode(std::stoi(data, &sz));
        data.erase(0, sz);
        q.push(root);
        while(data.length() > 0)
        {
            if(data.front() == ',')
            {
                data.erase(0, 1);
                continue;
            }
            
            TreeNode* node = NULL;
            if(data.front() != '#')
            {
                node = new TreeNode(std::stoi(data, &sz));
            }
            
            if(bLeft)
            {
                q.front()->left = node;
            }
            else
            {
                q.front()->right = node;
                q.pop();
            }
            bLeft = !bLeft;
            
            if(node)
                q.push(node);
            
            if(data.front() == '#')
                data.erase(0, 1);
            else
                data.erase(0, sz);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));