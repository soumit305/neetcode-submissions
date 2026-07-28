class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];
        for (int i = 1; i<strs.size(); i++){
            string s = strs[i];
            string new_lcp;
            for (int j = 0; j<min(lcp.size(),s.size()); j++){
                if (lcp[j]==s[j]) new_lcp.push_back(lcp[j]);
                else break;
            }
            lcp = new_lcp;
        }
        return lcp;
    }
};