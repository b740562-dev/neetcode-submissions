class Solution {
public:
    int lengthOfLongestSubstring(string arr) {

        // non duplicates aarhe to r++ karo jaise hi duplicates aaye to tab tak l++ karo jab tak 
        // duplicates hat na jaye 
        // length will be r-l+1 !!!!

        int n=arr.size();
        if(n==0){
            return 0;
        }
        unordered_set<int> st;
        int l=0, r=0, maxlen=1;
        // we will not allow window to go below maxlen !!!
        while(r<n){
            while(st.find(arr[r])!=st.end()){
                st.erase(arr[l]);
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            st.insert(arr[r]);
            r++;
        }
        return maxlen;
    }
};
