class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (string s : strs){
            for (int i = 0; i<min(s.size(),ans.size()); i++){
                if (s[i]==ans[i]) continue;
                else {
                    ans = ans.substr(0,i);
                }
            }
        }
        return ans;
    }
};