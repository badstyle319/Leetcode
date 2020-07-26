class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0, i=0, j=0;
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                ans++;
                j++;
                i++;
            }else
                i++;
        }
        return ans;
    }
};