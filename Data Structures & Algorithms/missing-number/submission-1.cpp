class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i<n; i++ ){
            if ((i ^ nums[i]) != 0) return i;
        }
        return -1;
    }
};
