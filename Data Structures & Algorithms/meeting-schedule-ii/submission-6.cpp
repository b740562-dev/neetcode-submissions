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
    int minMeetingRooms(vector<Interval>& intervals) {
        // just need to count overlapping intervals----min rooms needed means we want min overlap
        int n=intervals.size(); 
        if(n==0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),comp);

        // pq will store endings of all 
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(intervals[0].end);

        int cnt=1;
        for(int i=1;i<n;i++){

            if(intervals[i].start>=pq.top()){
                pq.pop();
            }

            pq.push(intervals[i].end);
            
        }
        return pq.size();
    }
};
