class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Check Boundary 
        if (target < matrix[0][0]) return false;
        if (target > matrix[m-1][n-1]) return false;
        // First Column search to find out the row
        int l = 0;
        int r = m-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if (target==matrix[mid][0]) return true;
            else if (target<matrix[mid][0]) r = mid-1;
            else if (target>matrix[mid][0]) l = mid+1;
        }
        int row = r;

        // Search row to find out element
        l = 0;
        r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if (target==matrix[row][mid]) return true;
            else if (target<matrix[row][mid]) r = mid-1;
            else if (target>matrix[row][mid]) l = mid+1;
        }

        return false;
    }
};
