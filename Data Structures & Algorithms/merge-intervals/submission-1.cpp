class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();

        // see as the array is sorted so we don't have to think for 0th index just need to change the first index during overlap !!

        // we can change the last index here !!!!
        for(auto& it:intervals){
            if(ans.empty() || it[0]>ans.back()[1]){
                ans.push_back(it);
            }
            if(it[0]<=ans.back()[1]){
                ans.back()[1]=max(it[1],ans.back()[1]);
            }
        }

        return ans;

    }
};
