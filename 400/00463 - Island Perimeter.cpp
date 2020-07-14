class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int islands=0, neighbors=0;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[i].size();j++){
               if(grid[i][j]){
                   islands++;
                   if((j+1)<grid[i].size() && grid[i][j+1])
                        neighbors++;
                   if((i+1)<grid.size() && grid[i+1][j])
                        neighbors++;
               }
           }
       }
       return islands*4-neighbors*2;
    }
};