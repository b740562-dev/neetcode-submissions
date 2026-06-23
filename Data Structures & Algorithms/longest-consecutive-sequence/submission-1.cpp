class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // // one solution is to sort the array and check 
        // sort(nums.begin(),nums.end());
        // int n=nums.size(), cnt=0, maxi=0;
        // for(int i=0;i<n;i++){
        //     if(i==0||nums[i]==nums[i-1]+1){
        //         cnt++;
        //         maxi=max(maxi,cnt);
        //     }
        //     else if(nums[i]==nums[i-1]){
        //         continue;
        //     }
        //     else{
        //         cnt=1;
        //     }
        // }
        // return maxi;
// -----------------------------------------------------------------------------------------
        // without sorting !!!
        unordered_set<int> st;

        int n=nums.size();

        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        // for every element we check whether it's -1 is present in the array or not in order to 
        // get our starting point !!!!
        int maxi=0;
        for(auto it:st){
            // it may be probably our starting point !!!
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    // ye bich me it++ karke loop kharab kar doge !!!
                    x++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};
