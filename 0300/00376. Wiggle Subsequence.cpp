class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        
        int ans = 1;
        int status = -1; // 0:decending 1:ascending
        for(int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i-1];
            if(!diff) continue;
            
            if(status == -1)
            {
                status = diff > 0 ? 1 : 0;
                ans++;
            }
            else
            {
                if(status && diff > 0)
                    continue;
                if(!status && diff < 0)
                    continue;
                ans++;
                status = !status;
            }
        }
        
        return ans;
    }
};