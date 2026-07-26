class Solution {
    bool isValid(int row, int col, int m, int n){
        return (row>=0 && row<m && col>=0 && col<n);
    }
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = 1;

        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i<4; i++){
                int nx = x + delrow[i];
                int ny = y + delcol[i];
                if (isValid(nx,ny,m,n) && !visited[nx][ny] && grid[nx][ny]=='1'){
                    q.push({nx,ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n,0));
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (!visited[i][j] && grid[i][j]=='1'){
                    bfs(i,j,visited,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
