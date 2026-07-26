class Solution {
public:

    string encode(vector<string>& strs) {
        string msg;
        for (string str : strs){
            msg += str;
            msg += "#";
        }
        return msg;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string temp;
        for (char c : s){
            if (c=='#' && cnt) {
                decoded.push_back(temp);
                temp = "";
                continue;
            }
            temp.push_back(c);
        }
        return decoded;
    }
};
