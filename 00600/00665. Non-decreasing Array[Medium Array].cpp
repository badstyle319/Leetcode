class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        int prev = nums[0];
        bool modified = false;
        
        for(int i = 1; i < len; i++)
        {
            if(nums[i] >= prev)
            {
                prev = nums[i];
            }
            else
            {
                if(modified)
                    return false;
                
                modified = true;
                if(i - 2 < 0 || nums[i] >= nums[i - 2])
                    prev = nums[i];
            }
        }
        
        return true;
    }
};