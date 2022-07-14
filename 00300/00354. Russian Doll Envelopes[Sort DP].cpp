class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int ans = 1;
        
        sort(envelopes.begin(), envelopes.end(),
            [](const vector<int>& v1, const vector<int>& v2)
             {
                 if(v1[1]==v2[1])
                     return v1[0] > v2[0];
                 else
                     return v1[1] > v2[1];
             });
        
        vector<int> dp(envelopes.size(), 1);
        for(auto row:envelopes)
        {
            for(auto n:row)
            {
                cout << n << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        for(int i = 1; i < envelopes.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};