class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,curr,ans,nums);
        return ans;
    }
    void solve(int idx, vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums){
        int n = nums.size();
        ans.push_back(curr);
        for (int i = idx; i<n; i++){
            if (i>idx && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            solve(i+1,curr,ans,nums);
            curr.pop_back();
        }
    }
};
