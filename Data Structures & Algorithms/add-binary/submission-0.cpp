class Solution {
public:
    string addBinary(string a, string b) {
        int ita = a.size()-1;
        int itb = b.size()-1;
        int sum;
        int carry = 0;
        string ans;
        while(ita>-1 && itb>-1){
            int a_dig = a[ita]-'0';
            int b_dig = b[itb]-'0';
            sum = (a_dig ^ b_dig ^ carry);
            carry = (a_dig & b_dig) | (a_dig & carry) | (carry & b_dig);
            ans.push_back(sum+'0');
            ita--; itb--;
        }
        while (ita>-1){
            int a_dig = a[ita]-'0';
            sum = (a_dig ^ carry);
            carry = (a_dig & carry);
            ans.push_back(sum+'0');
            ita--;
        } 
        while (itb>-1){
            int b_dig = b[itb]-'0';
            sum = (b_dig ^ carry);
            carry = (b_dig & carry);
            ans.push_back(sum+'0');
            itb--;
        }
        if (carry) ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};