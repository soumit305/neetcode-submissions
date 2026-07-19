class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mpp;
        for (int x : nums){
            if (mpp.find(x)!=mpp.end()) return true;
            mpp[x]++;
        }
        return false;
    }
};