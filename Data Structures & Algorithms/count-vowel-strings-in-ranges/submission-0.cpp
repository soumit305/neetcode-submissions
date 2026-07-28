class Solution {
private: 
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int number_of_words = words.size();
        vector<int> number_of_vowel_strings;
        int prefix_number_of_vowel_strings = 0;
        for (string s : words){
            if (isVowel(s[0]) && isVowel(s[s.size()-1])) prefix_number_of_vowel_strings++;
            number_of_vowel_strings.push_back(prefix_number_of_vowel_strings);
        }
        vector<int> ans;
        for (auto it : queries){
            int start_ind = it[0];
            int end_ind = it[1];
            int num = number_of_vowel_strings[end_ind] - number_of_vowel_strings[start_ind];
            if (isVowel(words[start_ind][0])&&isVowel(words[start_ind][words[start_ind].size()-1])) num++;
            ans.push_back(num);
        }
        return ans;
    }
};