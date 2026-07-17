class Solution {
    int roblinear(vector<int>& nums,int l,int r) {
        // this q is of same as take and not take ----choose to rob and not choose to rob----max of the two
        int n=nums.size();
        // vector<int> dp(n,-1);
        // return f(n-1,nums,dp);

        // prev is saving max rob till prev index
        // pprev is storing max row till prev to prev index 
        int prev=nums[l];
        int pprev=0;
        for(int i=l+1;i<=r;i++){
            int rob=nums[i]+pprev;
            int nottrob=prev;
            int curr=max(rob,nottrob);
            pprev=prev;
            prev=curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        
        // need to handle the case when n=1 as n-2 becomes <0 and accessing nums[r] will break the code 
        int n=nums.size();

        if(n==1){
            return nums[0];
        }

        int ans1=roblinear(nums,0,n-2);
        int ans2=roblinear(nums,1,n-1);

        return max(ans1,ans2);
    }
};
