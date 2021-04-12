class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int i, left = 1, right = n;
        
        for(i = 0; i < k; i++)
        {
            ans.push_back(i % 2 ? (right--) : (left++));
        }
        if(i % 2)
        {
            for(; i < n; i++)
                ans.push_back(left++);
        }
        else
        {
            for(; i < n; i++)
                ans.push_back(right--);
        }
        
        return ans;
    }
};