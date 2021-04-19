class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target + 1);
        
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for(int i = 1; i <= target; i++)
        {
            for(auto &num : nums)
            {
                if(i < num) break;
                
                dp[i] += dp[i - num];
                dp[i] %= INT_MAX;
            }
        }
        
        return dp[target];
    }
};