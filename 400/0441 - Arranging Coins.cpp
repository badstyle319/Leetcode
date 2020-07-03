class Solution {
public:
    int arrangeCoins(int n) {
        
        long sum = 0;
        for(int i = 1; ; i++)
        {
            sum += i;
            if(sum > n)
                return (i-1);
            else if(sum == n)
                return i;
        }
        return 0;
    }
};