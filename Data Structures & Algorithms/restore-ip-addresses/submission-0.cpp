class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr;
        solve(0, curr, 0, 4, s, ans);
        return ans;
    }
    void solve(int idx, string curr, int sum, int count, string& s, vector<string>& ans) {
        int n = s.size();
        if (idx == n) {
            if (count == 0) {
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }
        if (count == 0) return;
        
        int val = 0;
        for (int len = 1; len <= 3 && idx + len <= n; ++len) {
            string part = s.substr(idx, len);
            val = stoi(part);
            if (val > 255 || (part[0] == '0' && len > 1)) break;
            solve(idx + len, curr + part + ".", 0, count - 1, s, ans);
        }
    }
};