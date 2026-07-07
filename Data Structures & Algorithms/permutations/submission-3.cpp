class Solution {
   private:
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<int>& freq) {
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            // unique integers are present !!!
            // each time we check the whole array because in 1,3,2----1 is marked for loop has been already called for 2 then when it will be called for 3 then 
            // again for loop checks 1 already marked then 2 !!
            if(!freq[i]){
                freq[i]=1;
                curr.push_back(nums[i]);
                solve(nums,curr,ans,freq);
                freq[i]=0;
                curr.pop_back();
            }
        }
    }
    // without using freq array
    void solve2(int idx,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(curr);
            return ;
        }
        // unique integers are present !!!
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            curr.push_back(nums[idx]);
            solve2(idx+1,nums,curr,ans);
            // popping back is the backtracking step !!!
            curr.pop_back();
            swap(nums[idx],nums[i]);
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        // one is by using freq array to store that an element has already been visited !!!
        vector<vector<int>> ans;
        vector<int> curr;
        int n=nums.size();
        vector<int> freq(n);
        solve2(0,nums,curr,ans);
        return ans;
    }
};
