class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        unordered_map<char,int> mp;
        unordered_map<char,int>::iterator it;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
            
        for(it=mp.begin();it!=mp.end();it++)
            ans+=it->second/2*2;
        if(s.size()>ans)
            ans++;
        return ans;
    }
};