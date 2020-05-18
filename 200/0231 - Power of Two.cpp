/*
	only one bit of n is '1'
	return n>0 && !(n&(n-1));
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<33> bs(n);
        return bs.count()==1;
    }
};