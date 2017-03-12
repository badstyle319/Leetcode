class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> values;
        int hour, minute, ans=1e9, dif;
        const int dayMinutes = 60*24;
        
        for(int i=0;i<timePoints.size();i++){
            sscanf(timePoints[i].c_str(), "%d:%d", &hour, &minute);
            values.push_back(60*hour+minute);
        }
        
        sort(values.begin(), values.end());
        
        for(int i=1;i<values.size();i++){
            dif = values[i]-values[i-1];
            ans = min(ans, min(dif, dayMinutes-dif));
        }
        dif = values.back()-values.front();
        ans = min(ans, min(dif, dayMinutes-dif));
        return ans;
    }
};