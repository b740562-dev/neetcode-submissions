class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] represents that till index i from last of string s is it possible to match the worddict !!!
        int n1=s.size(), n2=wordDict.size();
        vector<int> dp(n1+1,0);
        dp[n1]=1;
        for(int i=n1-1;i>=0;i--){
            for(string &w : wordDict){
                int n3=w.size();
                if(i+n3<=n1 && s.substr(i,n3)==w){
                    // as dp[8] was true. So, if code word matches then i=4 will take value of i=8
                    dp[i]=dp[i+n3];
                }
                // this is done because suppose our dict contain ["cats","cat"] then cats subsstirng of s is when compared with 
                // cats it marked true but again on comparison with 
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};
