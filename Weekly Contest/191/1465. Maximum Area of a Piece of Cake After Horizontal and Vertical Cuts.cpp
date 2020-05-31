class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long wMax = 0;
        long hMax = 0;
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.push_back(h);
        for(int i = 0; i < horizontalCuts.size() - 1; i++)
        {
            wMax = max(wMax, (long)abs(horizontalCuts[i] - horizontalCuts[i+1]));
        }
        
        sort(verticalCuts.begin(), verticalCuts.end());
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.push_back(w);
        for(int i = 0; i < verticalCuts.size() - 1; i++)
        {
            hMax = max(hMax, (long)abs(verticalCuts[i] - verticalCuts[i+1]));
        }
        
        long ans = hMax * wMax % (long)(1e9 + 7);
        return ans;
    }
};