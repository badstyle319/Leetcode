class Solution {
public:
    string longestPalindrome(string s) {
        string ans(1, s[0]);
        for(int i=0;i<s.length();i++){
            for(int left=i-1,right=i+1;left>=0,right<s.length();left--,right++){
                if(s[left]==s[right]){
                    if(right-left+1>ans.length()){
                        ans = s.substr(left, right-left+1);
                    }
                }else
                    break;
            }
            for(int left=i,right=i+1;left>=0,right<s.length();left--,right++){
                if(s[left]==s[right]){
                    if(right-left+1>ans.length()){
                        ans = s.substr(left, right-left+1);
                    }
                }else
                    break;
            }
        }
        return ans;
    }
};