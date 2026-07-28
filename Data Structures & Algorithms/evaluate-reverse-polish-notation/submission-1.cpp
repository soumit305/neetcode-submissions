class Solution {
public:
    bool isOperator(string s){
        return (s=="+"||s=="*"||s=="-"||s=="/");
    }
    int evaluate(int s1, int s2, string s){
        if (s=="+") return s1 + s2;
        if (s=="-") return s1 - s2;
        if (s=="*") return s1 * s2;
        if (s=="/") return s1 / s2;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens){
            if (isOperator(s)){
                int s1 = st.top(); st.pop();
                int s2 = st.top(); st.pop();
                st.push(evaluate(s2,s1,s));
                continue;
            }
            st.push(stoi(s));
        }
        return st.top();
    }
};
