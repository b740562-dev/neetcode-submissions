class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // see the problem has 3 cases :
        // no zeros---1zero---multiple zeros 

        // keeping track of zerocnt will help 

        int n=nums.size();
        int productwithoutzero=1, zerocnt=0;
        for(int num:nums){
            if(num==0){
                zerocnt++;
            }
            else{
                productwithoutzero*=num;
            }
        }

        // ans[i]=0 for zerocnt >1 !!!
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            if(zerocnt==1){
                if(nums[i]!=0){
                    ans[i]=0;
                }
                else{
                    ans[i]=productwithoutzero;
                }
            }
            else if(zerocnt==0){
                ans[i]=productwithoutzero/nums[i];
            }
        }
        return ans;
    }
};
