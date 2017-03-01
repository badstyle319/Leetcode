class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        for(int i=0,j=0;i<nums.size();i++){
            if(nums[i]){
                ans = max(ans, 1);
                while(++j<nums.size() && nums[j]){
                    ans = max(ans, j-i+1);
                }
                i = j;
            }
        }
        return ans;
    }
};