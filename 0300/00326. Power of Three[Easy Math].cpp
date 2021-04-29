class Solution {
public:
    bool isPowerOfThree(int n) {
        /***sol.1
        if(n < 1)
            return false;
        
        while(n % 3 == 0)
        {
            n /= 3;
        }
        
        return n == 1;
        ***/
        
        int maxPower = floor(log(INT_MAX)/log(3));
        int maximum = pow(3.0, (double)maxPower);
        
        return n > 0 && maximum % n == 0;
    }
};