class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAmountOfWater = INT_MIN;
        int l = 0;
        int r = heights.size()-1;
        while(l<r){
            int amount = min(heights[l],heights[r])*(r-l);
            maxAmountOfWater = max(maxAmountOfWater,amount);
            if (heights[l]<heights[r]) l++;
            else r--;
        }
        return maxAmountOfWater;
    }
};
