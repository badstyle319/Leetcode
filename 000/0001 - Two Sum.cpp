class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        map<int, int> mp;
        
        for(int i = 0; i < (int)nums.size(); i++)
        {
            int temp = target - nums[i];
            if(mp.count(temp))
            {
                ans.push_back(mp[temp]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};