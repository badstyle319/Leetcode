class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        long m1 = LONG_MIN;
        long m2 = LONG_MIN;
        long m3 = LONG_MIN;

        for(auto num:nums)
        {
            if(num == m1 || num == m2 || num == m3)
                continue;
            
            if(num > m1)
            {
                m3 = m2;
                m2 = m1;
                m1 = num;
            }
            else if(num > m2)
            {
                m3 = m2;
                m2 = num;
            }
            else if(num > m3)
            {
                m3 = num;
            }
        }
        
        return (m3 == LONG_MIN)? m1: m3;
    }
};