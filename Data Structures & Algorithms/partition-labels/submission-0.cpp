class Solution {
public:
    vector<int> partitionLabels(string s) {

        // for each character we have to store it's ending index 
        unordered_map<int,int> mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]-'a']=i;
        }

        vector<int> ans;
        int start=0, end=0;
        for(int i=0;i<n;i++){
            // end should be maximum of coming strings along way!!!
            // as new character appears index i will increased. So, end will be for sure updated !!!!
            end=max(end,mpp[s[i]-'a']);
            // at the point we reach the end we start fresh on next string !!
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }

        return ans;

    }
};
