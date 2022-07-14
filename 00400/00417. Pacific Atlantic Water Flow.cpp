class Solution {
    void dfs(vector<vector<int>>&matrix, int row, int col, int height, vector<vector<bool>> &visited)
    {
        if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size())
            return;
        if(visited[row][col] || matrix[row][col] < height) return;
        
        visited[row][col] = true;
        dfs(matrix, row - 1, col, matrix[row][col], visited);
        dfs(matrix, row + 1, col, matrix[row][col], visited);
        dfs(matrix, row, col + 1, matrix[row][col], visited);
        dfs(matrix, row, col - 1, matrix[row][col], visited);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.size()>0?matrix[0].size():0;
        if(m == 0 || n == 0)
            return {};
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
        {
            dfs(matrix, 0, i, 0, pacific);
            dfs(matrix, m-1, i, 0, atlantic);
        }
        for(int i = 0; i < m; i++)
        {
            dfs(matrix, i, 0, 0, pacific);
            dfs(matrix, i, n-1, 0, atlantic);
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};