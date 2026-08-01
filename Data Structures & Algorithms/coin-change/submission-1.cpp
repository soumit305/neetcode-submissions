class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans = minCoins(0,coins,amount,dp);
        return (ans==1e9) ? -1 : ans;
    }
    int minCoins(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        int n = coins.size();
        if (amount == 0) return 0;
        if (idx == n) return 1e9;
        if (dp[idx][amount]!=-1) return dp[idx][amount];
        int minPick = 1e9;
        // Pick
        if (amount>=coins[idx]) minPick = 1 + minCoins(idx,coins,amount-coins[idx],dp);
        // Not Pick
        int minNotPick = minCoins(idx+1,coins,amount,dp);
        return dp[idx][amount] = min(minPick,minNotPick);
    }
};
