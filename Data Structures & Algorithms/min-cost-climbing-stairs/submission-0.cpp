class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2,0);
        for (int idx = n-1; idx>=0; idx--){
            dp[idx] = cost[idx] + min(dp[idx+1],dp[idx+2]);
        }
        return min(dp[0],dp[1]);
    }
    int solve(int idx, vector<int>& cost){
        int n = cost.size();
        if (idx >= n) return 0;
        return cost[idx] + min(solve(idx+1,cost),solve(idx+2,cost));
    }
};
