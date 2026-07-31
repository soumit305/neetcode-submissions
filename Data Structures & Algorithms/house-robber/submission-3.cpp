class Solution {
public:
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n+2,0);
        // dp[n+1] = 0;
        // dp[n] = 0;
        // for (int i = n-1; i>=0; i--){
        //     int costPick = nums[i] + dp[i+2];
        //     int costNotPick = dp[i+1];
        //     dp[i] = max(costPick,costNotPick);
        // }
        // return dp[0];

        int n = nums.size();
        int prev = 0;
        int curr = 0;
        int ans = 0;
        for (int i = n-1; i>=0; i--){
            int costPick = nums[i] + prev;
            int costNotPick = curr;
            ans = max(costPick,costNotPick);
            prev = curr;
            curr = ans;
        }
        return curr;



        // return findMaxMoney(0,nums,dp);
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
