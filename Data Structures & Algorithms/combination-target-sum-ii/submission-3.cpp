class Solution {
   private:
    void traverse(int idx, vector<vector<int>>& ans, vector<int>& arr, int target,
                  vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }
            // target ki value decrease ho rhi hai !!!!
            if(arr[i]>target){
                break;
            }
            curr.push_back(arr[i]);
            traverse(i+1, ans, arr,target - arr[i],curr);
            curr.pop_back();
            // it's unneccesary because in the traverse function copy of the target is passed. So, during level traversal target value remain unchanged !!
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        // sort nums initially so that duplicates can be rejected !!!----VVI !!!!
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        traverse(0, ans, nums, target, curr);
        return ans;
    }
};
