class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int ans = INT_MAX;
        
        for(int L = 0, R = 0; L < nums.size() && R < nums.size();)
        {
            sum += nums[R];
            if(sum >= s)
            {
                ans = min(ans, R-L+1);
                while(sum - nums[L] >= s)
                {
                    sum -= nums[L];
                    L++;
                    ans = min(ans, R-L+1);
                }
            }
            R++;
        }
        
        return ans == INT_MAX?0:ans;
    }
};