class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int i=len/2;i>=1;i--){
            if(len%i==0){
                string target = s.substr(0, i);
                int cnt=1;
                for(int j=i;j<s.size();j+=i)
                    if(s.substr(j, i)==target)
                        cnt++;
                if(cnt==len/i)
                    return true;
            }
        }
        return false;
    }
};