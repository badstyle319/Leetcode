class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        map<int, int>::iterator it;
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(it=mp.begin();it!=mp.end();it++)
            if(it->second>floor(nums.size()/2)){
                ans = it->first;
                break;
            }
        return ans;
    }
};