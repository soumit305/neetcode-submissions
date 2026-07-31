class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return findMaxMoney(0,nums,dp);
    }
    int findMaxMoney(int idx, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        // Base
        if (idx >= n) return 0;
        if (dp[idx]!=-1) return dp[idx];
        // Pick
        int costPick = nums[idx] + findMaxMoney(idx+2,nums,dp);
        // Not Pick
        int costNotPick = findMaxMoney(idx+1,nums,dp);
        
        return dp[idx] = max(costPick,costNotPick);
    }
};
