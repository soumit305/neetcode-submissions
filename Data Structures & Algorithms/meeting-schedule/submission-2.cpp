/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int earliest  = INT_MAX;
        int latest = INT_MIN;
        for (auto it : intervals){
            if(it.start<latest && it.start>earliest) return false;
            if(it.end<latest && it.end>earliest) return false;
            if(it.start == earliest || it.end == latest) return false;
            if (it.start<earliest){
                earliest = it.start;
            }
            if (it.end>latest){
                latest = it.end;
            }
        }
        return true;
    }
};
