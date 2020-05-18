class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0)
            return 0;
        if(timeSeries.size()==1)
            return duration;
            
        int ans=duration, diff;
        for(int i=1;i<timeSeries.size();i++){
            diff = timeSeries[i]-timeSeries[i-1];
            if(diff<duration)
                ans+=diff;
            else
                ans+=duration;
        }
        return ans;
    }
};