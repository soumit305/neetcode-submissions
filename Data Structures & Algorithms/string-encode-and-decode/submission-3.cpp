class Solution {
public:

    string encode(vector<string>& strs) {
        string msg;
        for (string str : strs){
            msg += to_string(str.size()) + "#" + str;
        }
        return msg;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            // Find where the delimiter '#' is located
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            // Extract the length of the upcoming string
            int length = stoi(s.substr(i, j - i));
            // Move pointer past the '#' delimiter
            i = j + 1;
            // Extract the actual string using the known length
            decoded.push_back(s.substr(i, length));
            // Jump pointer to the start of the next encoded block
            i += length;
        }
        return decoded;
    }
};
