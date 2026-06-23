class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // q requires us to solve this problem without using / operator !!!
        // using prefix and postfix multiplying them in dynamic output array !!!

        // traversing from 0 to n-1 then n-1 back to 0 !!!!
        int n=nums.size();

        vector<int> ans(n,1);

        int prefix=1, suffix=1;
        for(int i=0;i<n;i++){
            ans[i]*=prefix;
            prefix*=nums[i];
        }

        for(int i=n-1;i>=0;i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }

        return ans;

    }
};
