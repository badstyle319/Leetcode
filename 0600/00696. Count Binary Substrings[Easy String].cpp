class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, pre = 0, cur = 1;
        
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] != s[i - 1])
            {
                ans += min(pre, cur);
                pre = cur;
                cur = 1;
            }
            else
            {
                cur++;
            }
        }
        
        return ans + min(pre, cur);
    }
};