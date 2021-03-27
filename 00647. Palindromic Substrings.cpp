class Solution {
    int calc(string &s, int posL, int posR, int offset)
    {
        if(posL - offset < 0 || posR + offset >= s.size())
            return 0;
        if(s[posL-offset] != s[posR+offset])
            return 0;
        
        return 1 + calc(s, posL, posR, offset+1);
    }
public:
    int countSubstrings(string s) {
        int ans = s.size();
        
        for(int i = 0; i < s.size(); i++)
        {
            ans += calc(s, i, i, 1);
        }
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == s[i+1])
            {
                ans += 1 + calc(s, i, i+1, 1);
            }
        }

        return ans;
    }
};