class Solution {
public:
    int numSub(string s) {
        string t = s;
        for(int i = 0; i < s.length(); i++)
        {
            if(t[i] == '0')
                t[i] = ' ';
        }
        
        long long ans = 0;
        stringstream ss(t);
        string s1;
        while(ss >> s1)
        {
            long long n = s1.length();
            ans += (1 + n) * n / 2;
        }
        
        return ans % (1000000007);
    }
};