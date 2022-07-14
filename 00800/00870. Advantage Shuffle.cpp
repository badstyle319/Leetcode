class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        priority_queue<int> pqA;
        priority_queue<pair<int,int>> pqB;
        vector<int> ans;
        
        ans.resize(A.size(), -1);
        for(auto a:A)
            pqA.push(a);
        for(int i = 0; i < B.size(); i++)
            pqB.push(make_pair(B[i], i));
        
        
        while(!pqB.empty())
        {
            if(pqA.top() > pqB.top().first)
            {
                ans[pqB.top().second] = pqA.top();
                pqA.pop();
            }
            pqB.pop();
        }
        
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] == -1)
            {
                ans[i] = pqA.top();
                pqA.pop();
            }
        }
        
        return ans;
    }
};