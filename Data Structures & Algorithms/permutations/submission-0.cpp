class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> used(n,0);
        solve(curr,used,ans, nums);
        return ans;
    }

    void solve(vector<int>& curr, vector<int>& used, vector<vector<int>>& ans, vector<int>& nums){
        int n = nums.size();
        if (curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for (int i=0; i<n; i++){
            if (used[i]) continue;

            curr.push_back(nums[i]);
            used[i] = 1;

            solve(curr,used,ans, nums);

            curr.pop_back();
            used[i] = 0;
        }
    }


};
