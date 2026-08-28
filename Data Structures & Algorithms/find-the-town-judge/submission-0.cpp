class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> freqMap;
        vector<int> isTrust(n+1,0);
        int ans = -1;
        for (auto t: trust){
            freqMap[t[1]]++;
            isTrust[t[0]] = 1;
            if (freqMap[t[1]]==n-1 && !isTrust[t[1]]){
                ans = t[1];
            }
            if (ans != -1 && isTrust[ans]) ans = -1;
        }
        return ans;
    }
};