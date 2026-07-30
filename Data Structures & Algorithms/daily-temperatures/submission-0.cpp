class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> ans(n);
        for (int i = 0; i<n; i++){
            if (st.empty()){
                st.push({temperatures[i],i});
                continue;
            }
            while (!st.empty() && temperatures[i] > st.top().first){
                int ind = st.top().second;
                ans[ind] = i - ind;
                st.pop();
            } 
            st.push({temperatures[i],i});
        }
        return ans;
    }
};
