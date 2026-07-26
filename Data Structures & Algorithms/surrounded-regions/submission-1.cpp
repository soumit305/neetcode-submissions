class Solution {
private: 
    bool isValid(int row,int col, int m, int n){
        return (row>=0 && row<m && col>=0 && col<n);
    }
    void dfs(int row, int col,vector<vector<char>>& board, vector<vector<int>>& visited){
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        for (int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (isValid(nrow,ncol,m,n) && !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,board,visited);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        for (int i = 0; i<m; i++){
            if (board[i][0]=='O' && !visited[i][0]){
                dfs(i,0,board,visited);
            }
            else if (board[i][n-1]=='O' && !visited[i][n-1]){
                dfs(i,n-1,board,visited);
            }
        }
        for (int j = 0; j<n; j++){
            if (board[0][j]=='O' && !visited[0][j]){
                dfs(0,j,board,visited);
            }
            else if (board[m-1][j]=='O' && !visited[m-1][j]){
                dfs(m-1,j,board,visited);
            }
        }

        for (int i = 0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j]=='O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
