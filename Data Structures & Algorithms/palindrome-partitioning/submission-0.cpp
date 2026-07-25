class Solution {
private: 
    void solve(int idx, vector<string>& curr, vector<vector<string>>& ans, string s){
        int n = s.size();
        if (idx == n) ans.push_back(curr);
        for (int i = idx; i<n; i++){
            if (isPalindrome(idx,i,s)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(i+1,curr,ans,s);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(int l, int r, string s){
        while(l<r){
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,curr,ans,s);
        return ans;
    }
};
