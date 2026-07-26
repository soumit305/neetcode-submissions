class Solution {
private:
    bool isValid(int row, int col, int m , int n){
        return (row>=0 && row<m && col>=0 && col<n);
    }
    int bfs(queue<pair<int,int>>& q, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        int time = -1;

        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        while(!q.empty()){
            int size = q.size();
            for (int k = 0; k<size; k++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i<4; i++){
                    int nx = x + delrow[i];
                    int ny = y + delcol[i];
                    if (isValid(nx,ny,m,n) && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        return time;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int time = bfs(q,grid);

        for(int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time;

    }
};
