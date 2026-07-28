class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix_sum = 0;
        int max_sum = INT_MIN;
        for (int num : nums){
            prefix_sum += num;
            max_sum = max(max_sum, prefix_sum);
            if (prefix_sum < 0) prefix_sum = 0;
        }
        return max_sum;
    }
};
