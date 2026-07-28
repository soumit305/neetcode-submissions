class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums){
            total_sum += num;
        }
        int prefix_sum = 0;
        for (int i = 0; i<nums.size(); i++){
            if (total_sum - prefix_sum - nums[i] == prefix_sum) return i;
            prefix_sum += nums[i];
        }
        return -1;
    }
};