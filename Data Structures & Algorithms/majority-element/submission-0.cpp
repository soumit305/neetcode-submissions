class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n/2;
        unordered_map<int,int> freqMap;
        for (int num : nums){
            freqMap[num]++;
            if (freqMap[num] == target + 1) return num;
        }
        return -1;
    }
};