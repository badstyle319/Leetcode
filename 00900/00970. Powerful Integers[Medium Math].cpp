class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans;
        int m = x != 1 ? log(bound) / log(x) : 1;
        int n = y != 1 ? log(bound) / log(y) : 1;
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                int n = pow(x, i) + pow(y, j);
                if(n <= bound)
                    ans.insert(n);
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};