class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans = 0;
        set<int> s;
        
        s.insert(0);
        for(auto out:connections)
        {
            if(s.find(out[1]) != s.end())
                s.insert(out[0]);
            else if(s.find(out[0]) != s.end())
            {
                s.insert(out[1]);
                ans++;
            }
        }
        
        return ans;
    }
};