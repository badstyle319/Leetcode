class Solution {
    set<string> perfect;
    map<string,string> cap;
    map<string,string> vow;
    void toLower(string &s)
    {
        transform(s.begin(),s.end(),s.begin(),
                 [](char ch){return tolower(ch);});
    }
    void toVow(string &s)
    {
        transform(s.begin(), s.end(), s.begin(),
                 [](char ch){
                     switch(ch)
                     {
                         case 'a':
                         case 'e':
                         case 'i':
                         case 'o':
                         case 'u':
                             return '*';
                     }
                     return ch;
                 });
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for(auto word:wordlist)
        {
            perfect.insert(word);
            
            string low = word;
            toLower(low);
            if(!cap.count(low))
                cap[low] = word;
            
            string vs = low;
            toVow(vs);
            if(!vow.count(vs))
                vow[vs] = word;
        }
        
        vector<string> ans;
        for(auto query:queries)
        {
            if(perfect.count(query))
            {
                ans.push_back(query);
                continue;
            }
            
            string low = query;
            toLower(low);
            if(cap.count(low))
            {
                ans.push_back(cap[low]);
                continue;
            }
            
            string vs = low;
            toVow(vs);
            if(vow.count(vs))
            {
                ans.push_back(vow[vs]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};