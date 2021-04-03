class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(st.empty())
                {
                    continue;
                }
                s[i] = s[st.top()] = '*';
                st.pop();
            }
        }
        
        int counter = 0;
        for(auto &ch:s)
        {
            if(ch == '*')
            {
                counter++;
                ans = max(ans, counter);
            }
            else
            {
                counter = 0;
            }
        }
        
        return ans;
    }
};