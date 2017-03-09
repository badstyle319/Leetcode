class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
            
        int fab1=1;
        int fab2=2;
        int ans=0;
        for(int i=2;i<n;i++){
            ans = fab1+fab2;
            fab1 = fab2;
            fab2 = ans;
        }
        return ans;
    }
};