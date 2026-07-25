class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(0,curr,ans,candidates,target);
        return ans;
    }
    void solve(int idx, vector<int>& curr, vector<vector<int>>& ans, vector<int>& candidates, int target){
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = idx; i<n; i++){
            if (i > idx && candidates[i] == candidates[i-1]) continue;
            if (candidates[i]>target) break;
            curr.push_back(candidates[i]);
            solve(i+1,curr,ans,candidates,target-candidates[i]);
            curr.pop_back();
        }
    }
};
