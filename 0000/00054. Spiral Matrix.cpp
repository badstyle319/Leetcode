class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = (int)matrix.size();
        int C = R>0?(int)matrix[0].size():0;
        vector<int> v;
        
        if(R == 0)
            return v;
        
        vector<vector<bool>> flag(R, vector(C, false));
        int i = 0, j = -1, k = 0;
        
        while(v.size() < R * C)
        {
            static int dr[] = {0, 1, 0, -1};
            static int dc[] = {1, 0, -1, 0};
            
            int tr = i + dr[k];
            int tc = j + dc[k];
            if(tr >= 0 && tr < R && tc >= 0 && tc < C && !flag[tr][tc])
            {
                flag[tr][tc] = true;
                v.push_back(matrix[tr][tc]);
                i = tr;
                j = tc;
            }
            else
            {
                k++;
                k %= 4;
            }
        }
        
        return v;
    }
};