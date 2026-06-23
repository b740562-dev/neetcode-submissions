class Solution {
public:
    bool isAnagram(string s, string t) {

        // solution of hashing has O(NlogK) for ordered_map
        // k is the no. of distinct characters !!!!

        // for hash set O(logN) for hash map 
        int n=s.size(), m=t.size();

        // int i=0;
        if(n!=m){
            return 0;
        }
        
        // // searching is easy in unordered map !!!
        // unordered_map<char,int> mpp;

        // for(int i=0;i<n;i++){
        //     mpp[s[i]]++;
        // }

        // int j=0;
        // while(j<m && !mpp.empty()){
        //     if(mpp.find(t[j])==mpp.end()){
        //         return 0;
        //     }
        //     mpp[t[j]]--;
        //     if(mpp[t[j]]==0){
        //         mpp.erase(t[j]);
        //     }
        //     j++;
        // }
        // if(j==m && mpp.empty()){
        //     return 1;
        // }
        // return 0;

        // other solution of this problem is to freq array --- because of simpler code !!!
        // only elements from a to z will be present !!
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        // freq.empty() will never happen as it always contain 0 at it's each index !!!
        
        for(auto it:freq){
            if(it!=0){
                return 0;
            }
        }

        return 1;

    }
};
