class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> mp;
        
        for(int i = 0; i < (int)nums.size(); i++)
        {
            int temp = target - nums[i];
            if(mp.count(temp))
            {
                vector<int> v{mp[temp], i};
                return v;
            }
            mp[nums[i]] = i;
        }
        return vector<int>(2, 0);
    }
};