class Solution {
private:
    bool isColumn(int col, vector<string>& grid, int n){
        for (int i = 0; i<n; i++){
            if (grid[i][col] == 'Q') return false; 
        }
        return true;
    }
    bool isRow(int row, vector<string>& grid, int n){
        for (int i = 0; i<n; i++){
            if (grid[row][i] == 'Q') return false; 
        }
        return true;
    }
    bool isLeftDiagonal(int row, int col, vector<string>& grid, int n){
        int crow = row;
        int ccol = col;
        while (row-- && col--){
            if (grid[row][col] == 'Q') return false;
        }
        while (crow++ < n-1 && ccol++ < n-1){
            if (grid[crow][ccol] == 'Q') return false;
        }
        return true;
    }
    bool isRightDiagonal(int row, int col, vector<string>& grid, int n){
        int crow = row;
        int ccol = col;
        while (row++ < n-1 && col--){
            if (grid[row][col] == 'Q') return false;
        }
        while (crow-- && ccol++ < n-1){
            if (grid[crow][ccol] == 'Q') return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> grid;
        for (int i=0; i<n; i++){
            string row;
            for (int j = 0; j<n; j++){
                row.push_back('.');
            }
            grid.push_back(row);
        }
        solve(0,grid,ans,n);
        return ans;
    }

    void solve(int row, vector<string>& grid, vector<vector<string>>& ans, int n){
        if (row == n) {
            ans.push_back(grid);
            return;
        }
        for (int i = 0; i<n; i++){
            if (isColumn(i,grid,n) && isRow(row,grid,n) && isLeftDiagonal(row,i,grid,n) && isRightDiagonal(row,i,grid,n)){
                grid[row][i] = 'Q';
                solve(row+1,grid,ans,n);
                grid[row][i] = '.';
            }
        }
    }
};
