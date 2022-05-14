class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> ans(row, vector<int>(col, 200*100+1));
        ans[0][0] = grid[0][0];
        for(int i = 1; i < col; ++i) ans[0][i] = ans[0][i-1] + grid[0][i];
        for(int i = 1; i < row; ++i) ans[i][0] = ans[i-1][0] + grid[i][0];
        
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                ans[i][j] = grid[i][j] + min(ans[i-1][j], ans[i][j-1]);
            }
        }
        return ans[row-1][col-1];
    }
};