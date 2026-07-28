class Solution {
public:
    int minOperations(string s) {
        string pattern;
        int n = s.size();
        for (int i = 0; i<n; i++){
            if (i%2==0) pattern.push_back('0');
            else pattern.push_back('1');
        }
        int switches = 0;
        for (int i = 0; i<n; i++){
            if (s[i]!=pattern[i]) switches++;
        }
        return min(switches,n-switches);
    }
};