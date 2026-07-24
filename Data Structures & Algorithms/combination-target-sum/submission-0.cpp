class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> curr;
        solve(0,curr,res,nums,target);
        vector<vector<int>> ans;
        for (auto it : res){
            ans.push_back(it);
        }
        return ans;
    }
    void solve(int idx, vector<int>& curr, set<vector<int>>& res, vector<int>& nums, int target){
        int n = nums.size();
        if (target<0) return;
        if (target == 0){
            res.insert(curr);
            return;
        }
        if (idx == n) {
            if (target == 0){
                res.insert(curr);
            }
            return;
        }
        curr.push_back(nums[idx]);
        solve(idx,curr,res,nums,target-nums[idx]);
        solve(idx+1,curr,res,nums,target-nums[idx]);
        curr.pop_back();
        solve(idx+1,curr,res,nums,target);
    }
};
