class Solution {
private:
    bool isValid(int x, int y, int m, int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    void bfs(int row, int col, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});
        
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i<4; i++){
                int nx = x + delrow[i];
                int ny = y + delcol[i];
                if (isValid(nx,ny,m,n) && (grid[x][y]+1<grid[nx][ny])){
                    grid[nx][ny] = grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j]==0){
                    bfs(i,j,grid);
                }
            }
        }
    }
};
