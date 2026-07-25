class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,curr,ans, nums);
        return ans;
    }

    void solve(int idx,vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums){
        int n = nums.size();
        if (idx==n){
            ans.push_back(nums);
            return;
        }
        for (int i=idx; i<n; i++){
            swap(nums[idx],nums[i]);
            solve(idx+1,curr,ans,nums);
            swap(nums[idx],nums[i]);
        }
    }


};
