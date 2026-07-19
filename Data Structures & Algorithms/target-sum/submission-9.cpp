class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();

        // best approach 
        if((target+total)%2!=0 || total<abs(target)){
            return 0;
        }

        int sum=(total+target)/2;

        // till ind=i how many subsets will able to reach the sum!!!
        // always possible to acheive sum=0 and on a condition arr[0] is also possible to achieve !!!

        vector<int> prev(sum+1,0);
        prev[0]=1;
        
        if(nums[0]<=sum){
            prev[nums[0]]=1;
        }

        // most important thing here 
        if(nums[0]==0){
            prev[0]=2;
        }

        for(int i=1;i<n;i++){
            vector<int> curr(sum+1,0);
            curr[0]=1;
            for(int s=0;s<=sum;s++){
                int take=0;
                if(nums[i]<=s){
                    // curr is taken when number is allowed to be used multiple times !!!---we have to choose prev here !!!
                    take=prev[s-nums[i]];
                }
                int nottake=prev[s];
                curr[s]=take+nottake;
            }
            prev=curr;
        }
        return prev[sum];
    }
};
