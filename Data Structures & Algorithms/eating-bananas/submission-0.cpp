class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEl = INT_MIN;
        int minEl = INT_MAX;
        for (int num : piles){
            maxEl = max(maxEl,num);
            minEl = min(minEl,num);
        }
        int l = minEl;
        int r = maxEl;
        int minK = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            int days = 0;
            for (int pile : piles){
                if (pile%mid==0) days += (pile/mid);
                else days += (pile/mid)+1;
            }
            if (days<=h) {
                minK = min(minK, mid);
                r = mid-1;
            }
            else {
                l = mid + 1;
            }
        }
        return minK;
    }
};
