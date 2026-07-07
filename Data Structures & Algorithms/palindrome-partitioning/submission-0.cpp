class Solution {
private:
    void f(string s,vector<vector<string>>& ans,vector<string>& curr,int start){
        // int k is the partition index----ispar partition karke can we make valid substrings !!!
        if(start==s.size()){
            ans.push_back(curr);
            return ;
        }
        // we want every character to be our start index !!!
        for(int end=start;end<s.size();end++){
            string temp=s.substr(start,end-start+1);
            if(check(temp)){
                curr.push_back(temp);
                f(s,ans,curr,end+1);
                curr.pop_back();
            }
        }
    }
    bool check(string& s){
        int n=s.size();
        int ind=(n-1)/2;
        for(int i=0;i<=ind;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        f(s,ans,curr,0);
        return ans;
    }
};
