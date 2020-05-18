class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<nums1.size();i++)
            mp[nums1[i]] = 1;
        for(int i=0;i<nums2.size();i++){
            if(mp.count(nums2[i])){
                mp.erase(nums2[i]);
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};