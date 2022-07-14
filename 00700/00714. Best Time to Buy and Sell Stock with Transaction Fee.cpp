class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buying = 0, selling = -prices[0];
        for(auto &price:prices)
        {
            buying = max(buying, selling + price - fee);
            selling = max(selling, buying - price);
        }
        
        return buying;
    }
};