class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty())
            return 0;
        
        for(int L = 0, R = s.length() - 1; L < R; L++, R--)
        {
            if(s[L] != s[R])
                return 2;
        }
        return 1;
    }
};