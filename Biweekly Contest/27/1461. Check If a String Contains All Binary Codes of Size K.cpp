class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<int, bool> mp;

        if(s.substr(0, k) == string(k, '0'))
            mp[0] = true;
        for(int i = s.length()-k; i >= 0; i--)
        {
            bitset<32> bs(s.substr(i, k));
            long n = bs.to_ulong();
            mp[n] = true;
        }

        return (1 << k) == mp.size();
    }
};