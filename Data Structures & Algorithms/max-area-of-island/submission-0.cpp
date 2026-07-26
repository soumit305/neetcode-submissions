class Solution {
private: 
    bool isValid(int x, int y, int m, int n){
        return ( x>=0 && x<m && y>=0 && y<n);
    }
    int dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid){
        int area = 1;
        visited[row][col] = 1;

        int m = grid.size();
        int n = grid[0].size();


        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        for (int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (isValid(nrow,ncol,m,n) && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                area += dfs(nrow,ncol,visited,grid);
            }
        }

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (!visited[i][j] && grid[i][j]==1){
                    maxArea = max(maxArea,dfs(i,j,visited,grid));
                }
            }
        }
        return maxArea;
    }
};
