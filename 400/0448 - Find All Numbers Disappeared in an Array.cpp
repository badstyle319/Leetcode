class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = (int)nums.size();
        vector<int> ans;
        
        for(int i = 0; i < len; i++)
        {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0)
                nums[idx] *= -1;
        }
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] > 0)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};