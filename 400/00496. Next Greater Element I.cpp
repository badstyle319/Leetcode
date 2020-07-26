class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> mp;
        vector<int> result;
        
        for(int i=0;i<nums.size();i++)
            mp[nums[i]] = i;
        
        for(int i=0;i<findNums.size();i++){
            int found = 0;
            for(int j=mp[findNums[i]];j<nums.size();j++){
                if(nums[j]>findNums[i]){
                    result.push_back(nums[j]);
                    found = 1;
                    break;
                }
            }
            if(!found)
                result.push_back(-1);
        }
        return result;
    }
};