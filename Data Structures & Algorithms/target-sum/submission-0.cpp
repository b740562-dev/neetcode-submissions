class Solution {
    int f(int ind,int sum,vector<vector<int>>& dp,int target,vector<int>& nums,int total){
        if(ind==nums.size() && sum==target){
            return 1;
        }

        if(ind==nums.size()){
            return 0;
        }

        if(dp[ind][sum+total]!=-1){
            return dp[ind][sum+total];
        }
        
        // sum-nums[ind] can become <0. So, we will have use offset method !!
        int add=f(ind+1,sum+nums[ind],dp,target,nums,total);
        int sub=f(ind+1,sum-nums[ind],dp,target,nums,total);

        return dp[ind][sum+total]=add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // each no. has only two option !!!
        // we have to choose all the no.s !!!
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        // sum+-nums[ind] will stay between -total to +total !!!!
        vector<vector<int>> dp(n,vector<int>(2*total+1,-1));
        return f(0,0,dp,target,nums,total);
    }
};
