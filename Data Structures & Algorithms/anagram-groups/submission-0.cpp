class Solution {
private:
    bool valid_anagram(string& s1,string& s2){
        vector<int> freq(26,0);
        int n1=s1.length(), n2=s2.length();
        if(n1!=n2){
            return 0;
        }
        for(int i=0;i<n1;i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return 0;
            }
        }
        return 1;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {

        vector<vector<string>> ans;
        int m=s.size();
        
        unordered_map<string,int> mpp;

        for(int i=0;i<m;i++){
            string s1=s[i];
            sort(s1.begin(),s1.end());
            if(mpp.find(s1)==mpp.end()){
                ans.push_back({s[i]});
                // store the index at which string is stored in ans vector!!!
                mpp[s1]=ans.size()-1;
            }
            else{   
                // since the string already present in map. So, it's been visited earlier. 
                // So, just push current string at that index 
                ans[mpp[s1]].push_back(s[i]);
            }
        }

        return ans;
    }
};
