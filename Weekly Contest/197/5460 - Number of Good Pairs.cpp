class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        map<int, int> mp;
        for(int i = 0; i < (int)nums.size(); i++)
            mp[nums[i]]++;
        for(auto kv:mp)
        {
            int n = kv.second;
            if(n > 1)
            {
                ans += n * (n - 1) / 2;
            }
        }
        
        return ans;
    }
};