class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return 0;
        else if(len < 2)
            return -1;
        
        vector<pair<int,int>> v;
        
        for(int i = 0; i < len; i++)
            v.push_back(make_pair(nums[i], i));
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        
        if(v[0].first >= v[1].first * 2)
            return v[0].second;
        return -1;
    }
};