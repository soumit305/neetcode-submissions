class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int prefix_sum = 0;
        int cnt = 0;
        for (int num : nums){
            mpp[prefix_sum]++;
            prefix_sum += num;
            if (mpp.find(prefix_sum-k)!=mpp.end()){
                cnt += mpp[prefix_sum-k];
            }
        }
        return cnt;
    }
};