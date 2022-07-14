class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k)
            return false;
        
        set<string> dic;
        
        for(int i = 0; i < s.length() - k + 1; i++)
        {
            dic.insert(s.substr(i, k));
        }

        return dic.size() == (1<<k);
    }
};