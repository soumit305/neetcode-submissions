class Solution {
private: 
    bool solve(int idx, string word, int row, int col, vector<vector<char>>& board){
        if (idx == word.size()) return true;

        int m = board.size();
        int n = board[0].size();
        
        // 2. Boundary Check & Character Mismatch Check
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[idx]) {
            return false;
        }

        // 3. Prevent Re-visiting: Save original char and mask the cell
        char originalChar = board[row][col];
        board[row][col] = '#'; 

        // 4. Direction Arrays
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};
        
        // 5. Short-circuiting loop: Exit early the moment we find a path
        for (int k = 0; k < 4; k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            
            if (solve(idx + 1, word, nrow, ncol, board)) {
                return true; // No need to check other directions!
            }
        }
        
        // 6. Backtrack: Restore the original character for other search paths
        board[row][col] = originalChar;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i<m; i++){
            for (int j=0; j<n; j++){
                if (solve(0, word, i, j, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};
