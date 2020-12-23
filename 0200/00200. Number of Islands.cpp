class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i >=0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1')
        {
            grid[i][j] = '0';
            static int dx[] = {0, 1, 0, -1 };
            static int dy[] = {1, 0, -1, 0};
            for(int k = 0; k < 4; k++)
                dfs(grid, i+dx[k], j+dy[k]);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
//         // dfs
//         int ans = 0;
        
//         for(int i = 0; i < grid.size(); i++)
//         {
//             for(int j = 0; j < grid[i].size(); j++)
//             {
//                 if(grid[i][j] == '1')
//                 {
//                     ans++;
//                     dfs(grid, i, j);
//                 }
//             }
//         }
        
//         return ans;
        
        // bfs
        if(grid.size() == 0)
            return 0;
        
        vector< vector<bool> > visited;
        queue< pair<int,int> > q;
        int ans = 0;
        
        visited.resize(grid.size(), vector<bool>());
        for(int i = 0; i < grid.size(); i++)
            visited[i].resize(grid[i].size(), false);
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    
                    visited[i][j] = true;
                    ans++;
                    q.push(make_pair(i, j));
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        static int dx[] = {1, 0, -1, 0};
                        static int dy[] = {0, 1, 0, -1};
                        for(int k = 0; k < 4; k++)
                        {
                            int tx = x+dx[k];
                            int ty = y+dy[k];
                            if(tx >= 0 && tx < grid.size()
                              && ty >= 0 && ty < grid[0].size()
                              && !visited[tx][ty]
                              && grid[tx][ty] == '1')
                            {
                                visited[tx][ty] = true;
                                q.push(make_pair(tx, ty));
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};