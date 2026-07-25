class Solution {
private:
    unordered_map<char,string> dict = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    void solve(int idx, string& curr, vector<string>& ans, string& digits){
        int n = digits.size();
        if (idx == n){
            ans.push_back(curr);
            return;
        }
        for (char c : dict[digits[idx]]){
            curr.push_back(c);
            solve(idx+1,curr,ans,digits);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size()==0) return ans;
        string curr;
        solve(0,curr,ans,digits);
        return ans;
    }

};
