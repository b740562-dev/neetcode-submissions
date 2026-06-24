class Solution {
public:
    int lengthOfLongestSubstring(string arr) {

        // non duplicates aarhe to r++ karo jaise hi duplicates aaye to tab tak l++ karo jab tak 
        // duplicates hat na jaye 
        // length will be r-l+1 !!!!

        int n=arr.size();

        // to store unique characters !!!!
        unordered_set<char> st;
        int l=0, r=0, maxlen=0;
        // we will not allow window to go below maxlen !!!
        while(r<n){
            while(st.find(arr[r])!=st.end()){
                st.erase(arr[l]);
                l++;
            }
            // l will never cross r as we are not allowing to go our window below the maxlen of 1 !!!
            // it occurs by erase of the value from the set !!!!

            // first insert the unique element then increase maxlength !!!
            // it is done so that maxlen can be intialised with 0 !!!
            st.insert(arr[r]);
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
