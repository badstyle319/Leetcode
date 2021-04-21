class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = triangle[0][0];
        
        for(int i = 1; i < triangle.size(); i++)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                if(j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if(j + 1 == triangle[i].size())
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                if(i + 1 == triangle.size())
                {
                    if(j == 0)
                        ans = triangle[i][j];
                    else
                        ans = min(ans, triangle[i][j]);
                }
            }
        }
        
        return ans;
    }
};