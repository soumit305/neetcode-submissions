class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1,1);
        // for (int i = 2; i<=n; i++){
        //     int count = 0;
        //     count += dp[n-1];
        //     count += dp[n-2];
        //     dp[i] = count;
        // }
        return solve(n);
    }
    int solve(int n){
        if (n==0 || n==1) return 1;
        int count = 0;
        count += solve(n-1);
        count += solve(n-2);
        return count;
    }
};
