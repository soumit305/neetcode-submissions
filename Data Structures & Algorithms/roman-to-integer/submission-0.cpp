class Solution {
public:
    unordered_map<char,int> mpp = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int romanToInt(string s) {
        int sum = 0;
        int i = 0;
        while(i<s.size()-1){
            if (mpp[s[i]] < mpp[s[i+1]]){
                sum += mpp[s[i+1]]-mpp[s[i]];
                i = i + 2;
            } else {
                sum += mpp[s[i]];
                i++;
            }
        }
        if (i==s.size()-1) sum += mpp[s[i]];
        return sum;
    }
};