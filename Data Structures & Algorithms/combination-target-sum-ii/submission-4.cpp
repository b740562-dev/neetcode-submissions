class Solution {
   private:
    void f(int ind, vector<vector<int>>& ans, vector<int>& temp, int sum, vector<int>& nums,int target) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) {
                continue;
            }
            if (sum + nums[i] > target) {
                break;
            }
            temp.push_back(nums[i]);
            f(i + 1, ans, temp, sum + nums[i], nums, target);
            temp.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,ans,temp,0,nums,target);
        return ans;
    }
};
