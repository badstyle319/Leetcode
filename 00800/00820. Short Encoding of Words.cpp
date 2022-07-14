class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());
        
        for(auto &word:words)
        {
            for(int i = 1; i < word.size(); i++)
                s.erase(word.substr(i));
        }
        
        int ans = s.size();
        for(auto &w:s)
        {
            cout << w << endl;
            ans += w.size();
        }
        
        return ans;
    }
};