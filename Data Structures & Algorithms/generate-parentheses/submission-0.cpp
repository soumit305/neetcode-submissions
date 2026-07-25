class Solution {
private: 
    void solve(int open_count, int close_count, string& curr, vector<string>& ans){
        if (open_count == 0 && close_count == 0){
            ans.push_back(curr);
            return;
        }
        if (open_count) {
            curr.push_back('(');
            solve(open_count-1,close_count,curr,ans);
            curr.pop_back();
        }
        if (close_count>open_count){
            curr.push_back(')');
            solve(open_count,close_count-1,curr,ans);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        solve(n,n,curr,ans);
        return ans;
    }
};
