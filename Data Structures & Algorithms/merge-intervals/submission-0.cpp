bool comp(vector<int> i1, vector<int> i2){
    return i1[0] < i2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i<intervals.size(); i++){
            int interval_start = intervals[i][0];
            int interval_end = intervals[i][1];
            if (interval_start<=end){
                end = max (end,interval_end);
            }
            else {
                ans.push_back({start,end});
                start = interval_start;
                end = interval_end;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
