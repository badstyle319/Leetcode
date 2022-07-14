class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        map<char,int> mp;
        vector<string> ans;
        
        for(auto &str:B)
        {
            map<char,int> temp;
            for(auto &ch:str)
            {
                temp[ch]++;
            }
            for(auto it = temp.begin(); it != temp.end(); it++)
            {
                if(!mp.count(it->first))
                    mp[it->first] = it->second;
                else
                    mp[it->first] = max(mp[it->first], it->second);
            }
        }
        
        for(auto &str:A)
        {
            map<char,int> temp;
            for(auto &ch:str)
            {
                temp[ch]++;
            }
            bool allMatch = true;
            for(auto it = mp.begin(); it != mp.end() && allMatch; it++)
            {
                if(!temp.count(it->first) || temp[it->first] < mp[it->first])
                    allMatch = false;
            }
            if(allMatch)
                ans.push_back(str);
        }
        
        return ans;
    }
};