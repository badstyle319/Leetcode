class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans;
        stack<int> S;
        
        ans.resize(T.size(), 0);
        for(int i = 0; i < T.size(); i++)
        {
            while(!S.empty() && T[S.top()] < T[i])
            {
                ans[S.top()] = i - S.top();
                S.pop();
            }
            S.push(i);
        }
        
        return ans;
    }
};