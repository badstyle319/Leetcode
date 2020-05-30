class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector< set<int> > can(n, set<int>());
        for(auto out:prerequisites)
        {
            can[out[1]].insert(out[0]);
            can[out[1]].insert(can[out[0]].begin(), can[out[0]].end());
        }

        vector<bool> ans;
        for(auto out:queries)
        {
            ans.push_back(can[out[1]].find(out[0]) != can[out[1]].end());
        }
        return ans;
    }
};