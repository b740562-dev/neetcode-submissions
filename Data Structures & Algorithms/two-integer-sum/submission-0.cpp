class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // two sum never demands sorting !!! as two pointers demands sorting !!!
        map<int,int> mpp;
        mpp[nums[0]]=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int remain=target-nums[i];
            if(mpp.find(remain)!=mpp.end()){
                return {mpp[remain],i};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
