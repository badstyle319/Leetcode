class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        stack<char> S;
        string ans;

        for(int i = 0; i < len; i++)
        {
            if(s[i] == ' ')
            {
                while(!S.empty())
                {
                    ans.push_back(S.top());
                    S.pop();
                }
                ans.push_back(' ');
            }
            else
            {
                S.push(s[i]);
            }
        }
        while(!S.empty())
        {
            ans.push_back(S.top());
            S.pop();
        }
        
        return ans;
    }
};