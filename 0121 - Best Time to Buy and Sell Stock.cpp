/*
	Kadane's Algorithm
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, temp=0;
        for(int i=1;i<prices.size();i++){
            temp = max(0, temp+=prices[i]-prices[i-1]);
            ans = max(ans, temp);
        }
        return ans;
    }
};