/**
  * Author: Rookie118
  * Title: Number_of_Islands
  * Completion time: 2018-09-09
 */

class Solution {
public:
    void visitIsland(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visit)
    {
        visit[i][j] = true;
        if(i > 0 && grid[i-1][j] == '1' && !visit[i-1][j])
            visitIsland(i-1, j, grid, visit);
        if(i < grid.size()-1 && grid[i+1][j] == '1' && !visit[i+1][j])
            visitIsland(i+1, j, grid, visit);
        if(j > 0 && grid[i][j-1] == '1' && !visit[i][j-1])
            visitIsland(i, j-1, grid, visit);
        if(j < grid[i].size()-1 && grid[i][j+1] == '1' && !visit[i][j+1])
            visitIsland(i, j+1, grid, visit);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        vector<vector<bool>> visit;
        for(size_t i = 0; i < grid.size(); ++i)
        {
            size_t col = grid[0].size();
            vector<bool> temp(col, false);
            visit.push_back(temp);
        }
        int cn_island = 0;

        for(size_t i = 0; i < grid.size(); ++i)
        {
            for(size_t j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == '1' && !visit[i][j])
                {
                    visitIsland(i, j, grid, visit);
                    ++cn_island;
                }
            }
        }
        return cn_island;
    }
};