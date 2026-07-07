class Solution {
   private:
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<int>& freq) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                curr.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, curr, ans, freq);
                freq[i] = 0;
                curr.pop_back();
            }
        }
    }
    void next_permutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
        return;
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        // we want all possible permutation !!!
        vector<vector<int>> ans;
        // ans.push_back(nums);
        // vector<int> nums2=nums;
        // next_permutation(nums2);
        // while(nums!=nums2){
        //     ans.push_back(nums2);
        //     next_permutation(nums2);
        // }
        // return ans;

        // -------------------------------------------------------------------------------------------
        int n = nums.size();
        vector<int> curr;
        vector<int> freq(n, 0);
        solve(nums, curr, ans, freq);
        return ans;
    }
};
