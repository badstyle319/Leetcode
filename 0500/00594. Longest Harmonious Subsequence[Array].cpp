class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        
        for(auto &num : nums)
        {
            mp[num]++;
            if(mp.count(num+1))
                ans = max(ans, mp[num]+mp[num+1]);
            if(mp.count(num-1))
                ans = max(ans, mp[num]+mp[num-1]);
        }
        
        return ans;
    }
};