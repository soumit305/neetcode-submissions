class Solution {
public:
    string longestPalindrome(string s) {
        string lps;
        for (int i = 0; i<s.size(); i++){
            int l = i;
            int r = i;
            string curr;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                curr = s.substr(l,r-l+1);
                l--; r++;
            }
            if (curr.size()>lps.size()) lps = curr;

            l = i;
            r = i + 1;
            curr = "";
             while(l>=0 && r<s.size() && s[l]==s[r]){
                curr = s.substr(l,r-l+1);
                l--; r++;
            }
            if (curr.size()>lps.size()) lps = curr;
        }
        return lps;
    }
};
