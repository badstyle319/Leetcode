/*
Could you do it without using any loop / recursion?
return n>0 && 1162261467%n==0;
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n!=1){
            if(n%3)
                return false;
            n/=3;
        }
        return true;
    }
};