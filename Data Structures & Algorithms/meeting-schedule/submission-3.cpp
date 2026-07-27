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
    static bool comp(Interval& i1,Interval& i2){
        return i1.start<=i2.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=1;i<n;i++){
            if(intervals[i].start<intervals[i-1].end){
                return 0;
            }
        }
        return 1;
    }
};
