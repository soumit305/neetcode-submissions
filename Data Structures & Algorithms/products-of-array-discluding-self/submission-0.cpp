class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forwardProduct(n);
        vector<int> backwardProduct(n);
        int prefixProduct = 1;
        for (int i = 0; i<n; i++){
            prefixProduct *= nums[i];
            forwardProduct[i]=prefixProduct;
        }
        int suffixProduct = 1;
        for (int i = n-1; i>=0; i--){
            suffixProduct *= nums[i];
            backwardProduct[i]=suffixProduct;
        }
        vector<int> ans(n);
        for (int i = 0; i<n; i++){
            if (i==0){
                ans[i] = backwardProduct[i+1];
                continue;
            }
            if (i==n-1){
                ans[i] = forwardProduct[i-1];
                continue;
            }
            ans[i] = backwardProduct[i+1] * forwardProduct[i-1];
        }
        return ans;
    }
};
