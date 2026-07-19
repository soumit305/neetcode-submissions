class Solution {
public:
    bool isAnagram(string s, string t) {
        int ssize = s.size();
        int tsize = t.size();
        if (ssize!=tsize) return false;
        vector<int> arr(26,0);
        for (int i =0; i<ssize; i++){
            arr[s[i]-'a']++;
        }
        for (int i=0; i<tsize; i++){
            arr[t[i]-'a']--;
            if (arr[t[i]-'a']<0){
                return false;
            }
        }
        return true;
    }
};
