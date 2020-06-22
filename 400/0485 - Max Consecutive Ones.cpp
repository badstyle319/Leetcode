class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, counter = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i])
                counter++;
            else
                counter = 0;
            ans = max(ans, counter);
        }
 
        return ans;
    }
};