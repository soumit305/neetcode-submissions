class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        int maxi  = 1;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<i; j++){
                if (nums[i]==nums[j]+1 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};
