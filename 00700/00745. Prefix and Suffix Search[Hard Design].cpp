class WordFilter {
    unordered_map<string, int> um;
public:
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            for(int j = 1; j <= word.length(); j++)
            {
                string prefix = word.substr(0, j);
                for(int k = 0; k < word.length(); k++)
                {
                    string suffix = word.substr(k);
                    um[prefix + "#" + suffix] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string target = prefix + "#" + suffix;
        return um.count(target) ? um[target] : 0;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */