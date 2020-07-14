class Solution {
public:
    char findTheDifference(string s, string t) {
        int val=0;
        for(int i=0;i<s.size();i++)
            val^=s[i];
        for(int i=0;i<t.size();i++)
            val^=t[i];
        return (char)val;
    }
};