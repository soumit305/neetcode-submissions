class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<bool>> rowFind(n, vector<bool>(n+1,false));
        vector<vector<bool>> colFind(n, vector<bool>(n+1,false));
        vector<vector<bool>> boxFind(9, vector<bool>(n+1,false));
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                if (board[i][j]!='.'){
                    char num = board[i][j];
                    if (rowFind[i][num-'0'] || colFind[j][num-'0']|| boxFind[(i / 3) * 3 + (j / 3)][num-'0']){
                        return false;
                    }
                    rowFind[i][num-'0'] = true;
                    colFind[j][num-'0'] = true; 
                    boxFind[(i / 3) * 3 + (j / 3)][num-'0'] = true;
                    // if (!checkRow(num,i,j,board) || !checkCol(num,i,j,board) || !checkBox(num,i,j,board)){
                    //     return false;
                    // }
                }
            }
        }
        return true;
    }
    bool checkRow(char num, int row, int col, vector<vector<char>>& board){
        int n = board.size();
        for (int i =0; i<n; i++){
            if (i == col) continue;
            if (board[row][i]==num) return false;
        }
        return true;
    }
    bool checkCol(char num, int row, int col, vector<vector<char>>& board){
        int n = board.size();
        for (int i =0; i<n; i++){
            if (i == row) continue;
            if (board[i][col]==num) return false;
        }
        return true;
    }
    bool checkBox(char num, int row, int col, vector<vector<char>>& board){
        int n = board.size();
        for (int i =0; i<n; i++){
            
        }
        return true;
    }
};
