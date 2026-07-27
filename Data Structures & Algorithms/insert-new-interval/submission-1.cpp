class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& old, vector<int>& news) {

        int n=old.size();

        vector<vector<int>> ans;
        
        // instead of handling lots of edge cases we can do this in one pass using while loops 
        int i=0;

        while(i<n && news[0]>old[i][1]){
            ans.push_back(old[i]);
            i++;
        }

        // merge overlapping intervals 
        while(i<n && news[1]>=old[i][0]){
            news[0]=min(news[0],old[i][0]);
            news[1]=max(news[1],old[i][1]);
            i++;
        }

        ans.push_back(news);

        while(i<n){
            ans.push_back(old[i]);
            i++;
        }

        return ans;
    }
};
