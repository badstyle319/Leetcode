class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> dic1, dic2;
        vector<int> result;
        
        for(int i=0;i<nums1.size();i++)
            dic1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
            dic2[nums2[i]]++;
            
        
        for(unordered_map<int,int>::iterator it=dic1.begin();it!=dic1.end();it++)
            if(dic2.count(it->first)){
                int cnt = min(it->second, dic2[it->first]);
                result.insert(result.begin(), cnt, it->first);
            }
        
        return result;
    }
};