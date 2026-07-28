class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m-1, left = 0, right = n-1;
        vector<int> spiral;
        while (top < bottom && left < right){
            for (int i = left; i <= right; i++){
                spiral.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++){
                spiral.push_back(matrix[i][right]);
            }
            right--;
            for (int i = right; i >= left; i--){
                spiral.push_back(matrix[bottom][i]);
            }
            bottom--;
            for (int i = bottom; i >= top; i--){
                spiral.push_back(matrix[i][left]);
            }
            left++;
        }
        if (left==right){
            for (int i = top; i <= bottom; i++){
                spiral.push_back(matrix[i][right]);
            }
        } else if (top == bottom){
            for (int i = left; i <= right; i++){
                spiral.push_back(matrix[top][i]);
            }
        } 
        return spiral;
    }
};
