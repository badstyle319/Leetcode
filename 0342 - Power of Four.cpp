class Solution {
public:
    bool isPowerOfFour(int num) {
        bitset<33> bs(num);

        if(bs.count()!=1)
            return false;
        
        for(int i=0;i<=32;i++)
            if(bs[i])
                return !(i%2);

        return false;
    }
};