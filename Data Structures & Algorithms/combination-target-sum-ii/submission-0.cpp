class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> curr;
        solve(0,curr,res,candidates,target);
        for (vector<int> entry : res){
            ans.push_back(entry);
        }
        return ans;
    }
    void solve(int idx, vector<int>& curr, set<vector<int>>& res, vector<int>& candidates, int target){
        int n = candidates.size();
        if (target == 0) {
            res.insert(curr);
            return;
        }
        if (idx == n) return;

        curr.push_back(candidates[idx]);
        solve(idx+1,curr,res,candidates,target-candidates[idx]);
        curr.pop_back();
        solve(idx+1,curr,res,candidates,target);
    }
};
