class Solution {
public:
    int findComplement(int num) {
        int digits = 0;
        int t=num;
        while(t){
            digits++;
            t>>=1;
        }
        return ~num & ((1<<digits)-1);
    }
};