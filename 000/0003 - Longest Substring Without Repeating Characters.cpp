class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans = 0;
        int len = (int)s.length();
        int mp[256];
        
        memset(mp, -1, sizeof(mp));
        for(int L = 0, R = 0; L < len && R < len; R++)
        {
            if(mp[s[R]] == -1)
            {
                mp[s[R]] = R;
                ans = max(ans, R - L + 1);
            }
            else
            {
                for(int k = L; k < mp[s[R]]; k++)
                {
                    mp[s[k]] = -1;
                }
                L = mp[s[R]] + 1;
                mp[s[R]] = R;
            }
        }
        return ans;
    }
};