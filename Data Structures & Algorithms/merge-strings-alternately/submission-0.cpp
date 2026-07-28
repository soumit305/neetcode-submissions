class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 == 0) return word2;
        if (len2 == 0) return word1;
        string s;
        int it = 0;
        while (it < min(len1,len2)){
            s.push_back(word1[it]);
            s.push_back(word2[it]);
            it++;
        }
        if (len1 < len2){
            while(it<len2){
                s.push_back(word2[it]);
                it++;
            }
        } else {
            while (it<len1){
                s.push_back(word1[it]);
                it++;
            }
        }
        return s;
    }
};