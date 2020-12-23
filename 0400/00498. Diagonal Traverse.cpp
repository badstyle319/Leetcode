class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = R > 0 ? matrix[0].size() : 0; 
        vector<int> v, t;
        bool flag = true;
        vector<pair<int,int>> pos;
        
        for(int c = 0; c < C; c++)
            pos.push_back(make_pair(0, c));
        for(int r = 1; r < R; r++)
            pos.push_back(make_pair(r, C - 1));
        
        for(auto &p:pos)
        {
            t.clear();
            for(int r = p.first, c = p.second; r < R && c >= 0; r++, c--)
                t.push_back(matrix[r][c]);
            if(flag)
                reverse(t.begin(), t.end());
            flag = !flag;
            v.insert(v.end(), t.begin(), t.end());
        }
        
        return v;
    }
};