class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int row = og.size();
        int column = og[0].size();
        
        if(og[0][0] || og[row-1][column-1]) return 0;
        
        og[0][0] = 1;
        for(int i = 1; i < column; i++)
        {
            og[0][i] = !og[0][i] ? og[0][i-1] : 0;
        }
        for(int i = 1; i < row; i++)
        {
            og[i][0] = !og[i][0] ? og[i-1][0] : 0;
        }
        
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < column; j++)
            {
                og[i][j] = !og[i][j] ? (og[i-1][j] + og[i][j-1]) : 0;
            }
        }
        
        return og[row-1][column-1];
    }
};