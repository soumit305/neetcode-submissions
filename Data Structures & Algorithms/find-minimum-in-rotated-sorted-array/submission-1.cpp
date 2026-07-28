class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        if (nums[l]<nums[r]) return nums[l];
        int mini = INT_MAX;
        while (l<=r){
            int mid = l + (r-l)/2;
            mini = min(mini,nums[mid]);
            if (nums[mid] >= nums[r]){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return mini;
    }
};
