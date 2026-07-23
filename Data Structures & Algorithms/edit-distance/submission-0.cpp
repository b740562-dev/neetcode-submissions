class Solution {
    int f(int i,int j,vector<vector<int>>& dp,string& word1, string& word2){
        
        if(i==0){
            return j;
        }

        if(j==0){
            return i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i-1]!=word2[j-1]){
            int try1=1+f(i-1,j-1,dp,word1,word2);
            int try2=1+f(i-1,j,dp,word1,word2);
            int try3=1+f(i,j-1,dp,word1,word2);
            return dp[i][j]=min(try1,min(try2,try3));
        }

        return dp[i][j]=f(i-1,j-1,dp,word1,word2);

    }
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return f(n1,n2,dp,word1,word2);
    }
};
