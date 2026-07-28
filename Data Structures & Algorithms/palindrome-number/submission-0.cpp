class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int l = 0 ;
        int r = num.size()-1;
        while(l<r){
            if (num[l]!=num[r]) return false;
            l++; r--;
        }
        return true;
    }
};