class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>=2){
                return 1;
            }
        }
        return 0;
    }
};