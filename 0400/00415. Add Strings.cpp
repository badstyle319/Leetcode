class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int diff = num1.length()-num2.length();
        if(diff>0)
            num2.insert(0, diff, '0');
        else if(diff<0)
            num1.insert(0, -diff, '0');
            
        int carry = 0;
        for(int i=num1.length()-1;i>=0;i--){
            int digitSum = num1[i]-'0'+num2[i]-'0'+carry;
            ans.insert(0, 1, digitSum%10+'0');
            carry = digitSum/10;
        }
        if(carry)
            ans.insert(0, 1, carry+'0');
        return ans;
    }
};