class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        string bits = "0123456";
        int neg=0;
        
        if(num<0){
            neg = -1;
            num = -num;
        }
        
        int remainder=0;
        do{
            remainder = num%7;
            num/=7;
            ans.insert(0, 1, bits[remainder]);
        }while(num);
        if(neg)
            ans.insert(0, 1, '-');
        return ans;
    }
};