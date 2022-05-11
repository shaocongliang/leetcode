class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int ans = 0;
      vector<vector<char>> vis(grid.size());
      for(int i = 0 ; i < grid.size(); i++) {
         vis[i] = vector<char>(grid[i].size(), false);
      }
        
      for(int i = 0; i < grid.size(); ++i) {
          for(int j = 0; j < grid[i].size(); ++j) {
              if(grid[i][j] == '1' && vis[i][j] == false) {
                  ans++;
                  vis[i][j] = true;
                  dfs(i, j, grid, vis);
              }
          }
      }
      return ans;
    }
    
    bool inRange(int i, int j, int rowLen, int colLen) {
        return i >= 0 && i < rowLen && j >= 0 && j < colLen;
    }
    void dfs(int i, int j, const vector<vector<char>> &grid, vector<vector<char>> &vis) {
        static vector<pair<int, int>> vec = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}
        };
        int rowLen = grid.size();
        int colLen = grid[0].size();
        for(int a = 0; a < 4; a++){
            int x = i + vec[a].first;
            int y = j + vec[a].second;
            if(inRange(x, y, rowLen, colLen) && grid[x][y] == '1' && vis[x][y] == false){
                vis[x][y] = true;
                dfs(x, y, grid, vis);
            }
        }
        return;
    }
};