class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int,int> mp;
        unordered_map<int,int>::iterator it;
        int ans=0;
        for(int i=0;i<points.size();i++){
            mp.clear();
            for(int j=0;j<points.size();j++){
                if(i==j)
                    continue;
                int diff = (points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second);
                mp[diff]++;
            }
            for(it=mp.begin();it!=mp.end();it++){
                int temp = it->second;
                if(temp>=2)
                    ans+=temp*(temp-1);
            }
        }
        
        return ans;
    }
};