class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = x^y;
        int ans=0;
        while(val){
            if(val&1)
                ans++;
            val>>=1;
        }
        return ans;
    }
};