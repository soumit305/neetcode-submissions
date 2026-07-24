class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1,1);
        // for (int i = 2; i<=n; i++){
        //     int count = 0;
        //     count += dp[i-1];
        //     count += dp[i-2];
        //     dp[i] = count;
        // }
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
    int solve(int n, vector<int>& dp){
        if (n==0 || n==1) return 1;
        if (dp[n]!=-1) return dp[n];
        int count = 0;
        count += solve(n-1,dp);
        count += solve(n-2,dp);
        return dp[n] = count;
    }
};
