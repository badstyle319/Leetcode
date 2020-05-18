class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int rv = 0;
        int mp[256];
        memset(mp, -1, sizeof(mp));
        
        for(int i=0,j=0; i<s.length(),j<s.length();){
            if(mp[s[j]] == -1){
                mp[s[j]] = j;
                rv = max(rv, j-i+1);
            }else{
                for(int k=i;k<mp[s[j]];k++){
                    mp[s[k]] = -1;
                }
                i = mp[s[j]]+1;
                mp[s[j]] = j;
            }
            j++;
        }
        return rv;
    }
};