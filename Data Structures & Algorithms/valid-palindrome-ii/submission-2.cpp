class Solution {
public:
    
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false; // Fix: check s[l] != s[r]
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            if (s[l] != s[r]) {
                // Check both branches: skip left OR skip right
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }
};