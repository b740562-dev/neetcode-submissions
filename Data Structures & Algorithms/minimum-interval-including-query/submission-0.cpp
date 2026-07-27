class Solution {

public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        // see firstly we have to sort intervals and queries array !!!
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> q;

        int m=queries.size(), n=intervals.size();
        for(int i=0;i<m;i++){
            q.push_back({queries[i],i});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        sort(q.begin(),q.end());
        vector<int> ans(m,-1);

        // itreate in queries 
        int i=0;
        for(auto &it:q){
            int ele=it.first;
            int idx=it.second;

            // need to remove previously present element !!
            while(!pq.empty() && ele>pq.top().second){
                pq.pop();
            }

            // intervals pairs are sorted acc to first value !!!
            while(i<n && intervals[i][0]<=ele){
                if(intervals[i][1]>=ele){
                    pq.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                }
                i++;
            }
            ans[idx]=pq.empty() ? -1 : pq.top().first;
        }

        return ans;

    }
};
