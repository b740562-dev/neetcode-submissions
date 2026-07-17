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
        // if at ind-1 postion string contains 0 then it's not possible to comnbine the two strings !!!
        // obviously num<=26 tak hi map kar skte ho !!!
        if(s[ind-1]!='0' && num<=26){
            possi=f(ind-2,s,dp);
        }
        // if at ind position string contains 0 then it's not possible to take 0 as single character !!!
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
        // vector<int> dp(n,-1);
        // return f(n-1,s,dp);
        int prev=1;
        int pprev=1;
        for(int i=1;i<n;i++){
            int comb=0;
            int num=stoi(s.substr(i-1,2));
            if(s[i-1]!='0' && num<=26){
                comb=pprev;
            }
            int notcomb=0;
            if(s[i]!='0'){
                notcomb=prev;
            }
            int curr=comb+notcomb;
            pprev=prev;
            prev=curr;
        }
        return prev;
    }
};
