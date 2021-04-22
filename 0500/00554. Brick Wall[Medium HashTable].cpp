class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int ans = 0;
        
        for(int i = 0; i < wall.size(); i++)
        {
            int temp = 0;
            for(int j = 0; j < wall[i].size() - 1; j++)
            {
                temp += wall[i][j];
                mp[temp]++;
                ans = max(ans, mp[temp]);
            }
        }
        
        return wall.size() - ans;
    }
};