class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        
        dp[0] = 0;
        for(int i = 0; i <= amount; i++)
        {
            int smallest = INT_MAX;
            for(int coin:coins)
            {
                if(i < coin || dp[i - coin] == -1)
                    continue;
                smallest = min(smallest, dp[i - coin] + 1);
            }
            if(smallest != INT_MAX)
                dp[i] = smallest;
        }
        return dp[amount];
    }
};