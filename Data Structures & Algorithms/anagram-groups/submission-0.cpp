class Solution {
private:
    bool isAnagram(string s1, string s2){
        if (s1.size() != s2.size()) return false;
        vector<int> freq(26,0);
        for (char c : s1){
            freq[c-'a']++;
        }
        for (char c: s2){
            freq[c-'a']--;
            if (freq[c-'a']<0) return false;
        }
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        vector<int> visited(n,0);
        for (int i = 0; i<n; i++){
            if (visited[i]) continue;
            vector<string> group;
            group.push_back(strs[i]);
            for (int j= i+1; j<n; j++){
                if (isAnagram(strs[j],strs[i])) {
                    group.push_back(strs[j]);
                    visited[j] = 1;
                }
            }
            visited[i] = 1;
            ans.push_back(group);
        }
        return ans;
    }
};
