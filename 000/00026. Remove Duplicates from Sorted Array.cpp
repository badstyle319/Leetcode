class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = (int)nums.size();
        
        if(len == 0)
            return 0;
        
        int idx = 0;
        for(int i = 1; i < len; i++)
        {
            if(nums[idx] != nums[i])
            {
                idx++;
                nums[idx] = nums[i];
            }
        }
        
        return idx + 1;
    }
};