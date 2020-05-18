class Solution {
public:
    int addDigits(int num) {
        /*if(num<10)
            return num;
            
        stringstream ss;
        string numStr;
        int sum=0;
        
        ss<<num;
        numStr = ss.str();
        for(int i=0;i<numStr.size();i++)
            sum+=numStr[i]-'0';
        return addDigits(sum);*/
        return (num-1)%9+1;
    }
};