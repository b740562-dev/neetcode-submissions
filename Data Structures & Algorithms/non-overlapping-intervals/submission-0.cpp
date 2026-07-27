class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // [i-1][1] even if matches [i][0] then also we will call it overlapping !!!
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int end=intervals[0][1], cnt=0;

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=end){
                end=intervals[i][1];
                continue;
            }
            else{
                end=min(end,intervals[i][1]);
                cnt++;
            }
        }

        return cnt;
    }
};
