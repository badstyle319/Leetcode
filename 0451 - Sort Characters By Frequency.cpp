class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        map<int, string> cntMap;
        string ans="";
        
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
            if(!cntMap.count(it->second)){
                cntMap[it->second]="";
            }
            cntMap[it->second].append(it->second, it->first);
        }
        for(map<int, string>::iterator it=cntMap.begin();it!=cntMap.end();it++)
            ans.append(it->second);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};