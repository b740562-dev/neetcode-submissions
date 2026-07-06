class Solution {
   private:
    void traverse(int idx,vector<vector<int>>& ans, vector<int>& nums,int target, vector<int>& curr) {
        if (target==0) {
            ans.push_back(curr);
            return;
        }

        if(target<0){
            return;
        }

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>target){
                break;
            }
            curr.push_back(nums[i]);
            traverse(i+1,ans,nums,target-nums[i],curr);
            curr.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        // sort nums initially so that duplicates can be rejected !!!
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        traverse(0,ans,nums,target,curr);
        return ans;
    }
};
