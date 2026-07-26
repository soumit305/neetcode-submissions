class Solution {
public:
    int characterReplacement(string s, int k) {
        int replacements = 0;
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxLen = INT_MIN;
        while(r<n){
            if (s[l]==s[r]){
                r++;
                maxLen = max(maxLen,r-l);
            }
            else {
                if (replacements<k){
                    r++;
                    replacements++;
                    maxLen = max(maxLen,r-l);
                }
                else {
                    while(s[l]!=s[r]) {
                        if (replacements) replacements--;
                        l++;
                    }
                }
            }
        }
        return maxLen;
    }
};
