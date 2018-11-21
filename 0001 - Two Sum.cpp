class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> rv;
        int temp;
        
        for(int i=0;i<nums.size();i++){
            temp = target-nums[i];
            if(mp.count(temp)){
                rv.push_back(i);
                rv.push_back(mp[temp]);
                return rv;
            }
            mp[nums[i]] = i;
        }
        
        return rv;
    }
};