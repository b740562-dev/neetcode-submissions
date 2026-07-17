class Solution {
// no.of ways asked 
private:
    int f(int ind,string& s,vector<int>& dp){
        if(ind<=0){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int possi=0;
        int num=stoi(s.substr(ind-1,2));
        if(s[ind-1]!='0' && num<=26){
            possi=f(ind-2,s,dp);
        }
        int notpossi=0;
        if(s[ind]!='0'){
            notpossi=f(ind-1,s,dp);
        }
        return dp[ind]=possi+notpossi;
    }

public:
    int numDecodings(string s) {
        int n=s.size();
        // any string starting with 0 can't be mapped to any letter
        if(s[0]=='0'){
            return 0;
        }
        vector<int> dp(n,-1);
        return f(n-1,s,dp);
    }
};
