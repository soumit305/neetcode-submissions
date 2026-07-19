class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum;
        int carry;
        int n = digits.size();
        vector<int> ans;
        for (int i = n-1; i>=0; i--){
            if ( i == n-1){
                sum = (digits[i]+1)%10;
                carry = (digits[i]+1)/10;
            } else {
                sum = (digits[i]+carry)%10;
                carry = (digits[i]+carry)/10;
            }
            ans.push_back(sum);
        }
        if (carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
