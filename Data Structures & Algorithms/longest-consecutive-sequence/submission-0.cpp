class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
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
    // int solve(int idx, int curr_count, vector<int>& nums,unordered_map<int,int>& mpp){
    //     if (idx==nums.size()) return 0;
    //     int above  = 0;
    //     if (mpp.find(nums[idx]+1)!=mpp.end()) {
    //         mpp[]
    //         above = solve(idx+1,curr_count+1,nums,mpp);
    //     }
    // }
};
