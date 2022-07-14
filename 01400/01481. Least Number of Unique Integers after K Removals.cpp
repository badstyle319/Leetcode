class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        vector<pair<int,int>> v;
        
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for(auto kv:mp)
            v.push_back(make_pair(kv.second, kv.first));
        sort(v.begin(), v.end());
        for(auto pair:v)
        {
            if(k >= pair.first)
            {
                k -= mp[pair.second];
                mp.erase(pair.second);
            }
            else
                break;
        }
        return (int)mp.size();
    }
};