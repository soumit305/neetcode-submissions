class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> stt;
        for (int i=0; i< nums.size(); i++){
            if (stt.find(nums[i])!=stt.end()){
                if (i-stt[nums[i]]<=k) return true;
            }
            stt[nums[i]] = i;
        }
        return false;
    }
};