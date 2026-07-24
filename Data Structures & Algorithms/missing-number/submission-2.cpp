class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;
        int numXorSum = 0;
        for (int i = 0; i<=n; i++ ){
            xorSum = xorSum ^ i;
        }
        for (int i = 0; i<n; i++){
            numXorSum = numXorSum^nums[i];
        }
        return xorSum ^ numXorSum;
    }
};
