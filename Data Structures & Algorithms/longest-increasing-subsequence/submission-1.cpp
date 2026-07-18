class Solution {
private:
    // we need to keep track of two things always curr_ind and the prev_ind used to create the subsequence !!!
    int f(int ind,int prev,vector<int>& arr,int n,vector<vector<int>>& dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int nottake=f(ind+1,prev,arr,n,dp);
        int take=0;
        if(prev==-1 || arr[ind]>arr[prev]){
            take=1+f(ind+1,ind,arr,n,dp);
        }
        return dp[ind][prev+1]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(n,-1));
        // return f(0,-1,arr,n,dp);

        // using BS approach 
        vector<int> temp;
        temp.push_back(arr[0]);

        for(int i=1;i<n;i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                // this is valid if we only want length of lis and not the actual lis !!!!
                int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[ind]=arr[i];
            }
        }
        return temp.size();
    }
};
