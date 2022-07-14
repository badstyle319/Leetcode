class Solution {
    int square[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    unordered_map<int,int> mp;
public:
    bool isHappy(int n) {
        int sum=0, t=n;
        do{
            sum+=square[t%10];
            t/=10;
        }while(t);
        if(sum==1)
            return 1;
        if(mp.count(sum))
            return false;
        else{
            mp[n] = sum;
            return isHappy(sum);
        }
    }
};