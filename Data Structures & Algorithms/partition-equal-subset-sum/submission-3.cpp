class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // if a subset with sum=total_sum/2 exist then partition possible !!!
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return 0;
        }
        int k=sum/2;

        int n=nums.size();

        vector<bool> curr(k+1,0);
        curr[0]=1;

        if(k>=nums[0]){
            curr[nums[0]]=1;
        }

        for(int i=1;i<n;i++){
            for(int s=k;s>=0;s--){
                int nottake=curr[s];
                int take=0;
                if(nums[i]<=s){
                    // take requires us to use the prev array !!!
                    take=curr[s-nums[i]];
                }
                curr[s]=take||nottake;
            }
        }
        return curr[k];
    }
};
