class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0, j=0;i<nums.size() && j<nums.size();){
            while(nums[i] && i<nums.size())
                i++;
            j=i+1;
            while(!nums[j])
                j++;
            if(j>=nums.size())
                break;
            swap(nums[i], nums[j]);
            i++;
        }
    }
};