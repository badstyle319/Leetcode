class Solution {
public:
    string addBinary(string a, string b) {
        int len = max((int)a.length(), (int)b.length());
        
        if(a.length() < len)
            a.insert(0, len-a.length(), '0');
        if(b.length() < len)
            b.insert(0, len-b.length(), '0');
        
        string ans = "";
        int carry = 0;
        for(int i = len - 1; i >= 0; i--)
        {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            ans.insert(0, 1, sum % 2 + '0');
            carry = sum / 2;
        }
        if(carry)
            ans.insert(0, 1, '1');
        return ans;
    }
};