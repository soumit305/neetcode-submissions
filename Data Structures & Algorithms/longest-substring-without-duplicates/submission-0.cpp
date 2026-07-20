class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_set<char> stt;
        int maxi = 0;
        while (r<s.size()){
            while (stt.find(s[r])!=stt.end()){
                stt.erase(s[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
            stt.insert(s[r]);
            r++;
        }
        return maxi;
    }
};
