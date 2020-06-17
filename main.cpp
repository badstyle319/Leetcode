#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int len = (int)s.length();
        //abba a=0, b=1
        map<char, int> mp;
        for(int L = 0, R = 0; L < len && R < len;)
        {
            if(!mp.count(s[R]))
            {
                mp[s[R]] = R;
            }
            else
            {
                L = mp[s[R]] + 1;
                mp[s[R]] = R;
            }
            ans = max(ans, R-L+1);
            R++;
            
            for(auto kv:mp)
                cout<<kv.first<<","<<kv.second<<" ";
            cout<<endl;
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
	// clock_t begin = clock();
#endif
    
    Solution sol;
    string s;
    while(cin>>s)
    {
        string sTrimed = s.substr(1, s.length()-2);
        cout << sTrimed << ": " << sol.lengthOfLongestSubstring(sTrimed) <<endl;
        break;
    }
    
#ifdef DBG
	// clock_t end = clock();
	// double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    // cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}