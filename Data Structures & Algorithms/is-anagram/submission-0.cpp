class Solution {
public:
    bool isAnagram(string s, string t) {

        int n=s.size(), m=t.size();

        int i=0;
        if(n!=m){
            return 0;
        }

        map<char,int> mpp;

        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }

        int j=0;
        while(j<m && !mpp.empty()){
            if(mpp.find(t[j])==mpp.end()){
                return 0;
            }
            mpp[t[j]]--;
            if(mpp[t[j]]==0){
                mpp.erase(t[j]);
            }
            j++;
        }
        if(j==m && mpp.empty()){
            return 1;
        }
        return 0;
    }
};
