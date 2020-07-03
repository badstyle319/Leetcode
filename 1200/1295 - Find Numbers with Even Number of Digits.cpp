class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        
        for(auto num:nums)
        {
            int digit = 0;
            while(num)
            {
                digit++;
                num /= 10;
            }
            if(digit % 2 == 0)
                ans++;
        }
        
        return ans;
    }
};