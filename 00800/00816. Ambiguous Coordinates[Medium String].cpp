class Solution {
    vector<string> getStrings(string str)
    {
        vector<string> v;
        if(str.length() == 1 || str.back() == '0')
            v.push_back(str);
        else if(str.front() == '0')
            v.push_back(str.insert(1, "."));
        else
        {
            v.push_back(str);
            for(int i = 1; i < str.length(); i++)
            {
                string temp = str;
                v.push_back(temp.insert(i, "."));
            }
        }
        return v;
    }
    
    void generate(string strL, string strR, vector<string> &v)
    {
        vector<string> L = getStrings(strL);
        vector<string> R = getStrings(strR);
        
        for(auto &str1:L)
        {
            for(auto &str2:R)
            {
                v.push_back("(" + str1 + ", " + str2 + ")");
            }
        }
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        
        for(int i = 1; i < s.length() - 2; i++)
        {
            string L = s.substr(1, i);
            if(i > 1 && L == string(i, '0')) continue;
            if(L.length() > 2 && L.front() == '0' && L.back() == '0') continue;
            
            string R = s.substr(i + 1, s.length() - i - 2);
            if(R.length() > 1 && R == string(R.length(), '0')) continue;
            if(R.length() > 2 && R.front() == '0' && R.back() == '0') continue;
            
            generate(L, R, ans);
        }
        
        return ans;
    }
};