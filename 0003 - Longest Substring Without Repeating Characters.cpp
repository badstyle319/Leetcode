#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans = 0;
        int len = (int)s.length();
        set<char> st;
        deque<char> d;
        
        for(int i = 0; i < len; i++)
        {
            if(!st.count(s[i]))
            {
                st.insert(s[i]);
                d.push_back(s[i]);
            }
            else
            {
                while(d.front() != s[i])
                {
                    st.erase(d.front());
                    d.pop_front();
                }
                d.pop_front();
                d.push_back(s[i]);
            }    
            ans = max(ans, (int)d.size());
        }
        
        return ans;
    }
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef DBG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    Solution sol;
    string line;
    while(cin>>line)
    {
        string s = line.substr(1, line.length()-2);
        cout<<line<<":"<<sol.lengthOfLongestSubstring(s)<<endl;
    }
    
#ifdef DBG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}