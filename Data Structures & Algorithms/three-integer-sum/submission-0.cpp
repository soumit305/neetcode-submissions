class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        int n= nums.size();
        for (int i = 0; i<n; i++){
            unordered_set<int> sett;
            for (int j=i+1; j<n; j++){
                if (sett.find(-nums[i]-nums[j])!=sett.end()){
                    vector<int> entry = {nums[i],nums[j],-nums[i]-nums[j]};
                    sort(entry.begin(),entry.end());
                    res.insert(entry);
                }
                sett.insert(nums[j]);
            }
        }
        vector<vector<int>> ans;
        for (auto it : res){
            ans.push_back(it);
        }
        return ans;
    }
};
