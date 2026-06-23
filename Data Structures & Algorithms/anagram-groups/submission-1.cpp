class Solution {

private:
    vector<int> count_frequency(string& s){
        vector<int> count(26);

        for(char c:s){
            count[c-'a']++;
        }
        return count;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {

        // my approach is N*k*logk.....q is demanding N*K approach(max value of K is 26. So, log26 is not a much 
        // bigger value!!).....we have to avoid sorting !!!

        vector<vector<string>> ans;
        // int m=s.size();
        
        // unordered_map<string,int> mpp;

        // for(int i=0;i<m;i++){
        //     string s1=s[i];
        //     sort(s1.begin(),s1.end());
        //     if(mpp.find(s1)==mpp.end()){
        //         ans.push_back({s[i]});
        //         // store the index at which string is stored in ans vector!!!
        //         mpp[s1]=ans.size()-1;
        //     }
        //     else{   
        //         // since the string already present in map. So, it's been visited earlier. 
        //         // So, just push current string at mpp[s1] index !!!
        //         ans[mpp[s1]].push_back(s[i]);
        //     }
        // }
        // return ans;
// -----------------------------------------------------------------------------------------
        // for O(N*K) approach :

        // for each string uska freq array me wo string push kar do

        // int[26]=vector<int>(26)!!!
        map<vector<int>,vector<string>> mpp;

        for(string t:s){
            vector<int> freq_array=count_frequency(t);
            // see mpp[freq_array] is a vector----to store an element in vector need to use push
            // _back !!!
            mpp[freq_array].push_back(t);
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
