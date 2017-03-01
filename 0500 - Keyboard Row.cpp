class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mp;
        vector<string> result;
        
        string strs[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for(int i=0;i<3;i++){
            for(int j=0;j<strs[i].size();j++)
                mp[strs[i][j]] = i;
        }
        for(int i=0;i<words.size();i++){
            set<int> s;
            for(int j=0;j<words[i].size();j++){
                s.insert(mp[tolower(words[i][j])]);
                if(s.size()>1)
                    break;
            }
            if(s.size()==1)
                result.push_back(words[i]);
        }
        return result;
    }
};