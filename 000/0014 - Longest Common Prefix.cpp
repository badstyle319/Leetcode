class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = (int)strs.size();
        
        if(len == 0)
            return "";
        
        if(len == 1)
            return strs[0];
        
        string ans = "";
        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs[0].length(); i++)
        {
            for(int j = 1; j < len; j++)
            {
                if(strs[0][i] != strs[j][i])
                    return ans;
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};