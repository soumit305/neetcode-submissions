class Solution {
private:
    void setRow(int row,vector<vector<int>>& matrix){
        int n = matrix[0].size();
        for (int j = 0; j<n; j++){
            matrix[row][j] = 0;
        }
    }
    void setCol(int col,vector<vector<int>>& matrix){
        int m = matrix.size();
        for (int i = 0; i<m; i++){
            matrix[i][col] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int top_left=1;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i==0 && matrix[i][j] == 0) top_left = 0;
                else if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i<m; i++){
            if (matrix[i][0]==0) setRow(i,matrix);
        }
        for (int j = 0; j<n; j++){
            if (matrix[0][j]==0) setCol(j,matrix);
        }
        if (top_left == 0) setRow(0,matrix);
    }
};
