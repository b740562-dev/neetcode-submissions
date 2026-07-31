class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(string &s:strs){
            ans+=to_string(s.size())+'#'+s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n=s.size();
        int i=0;
        while(i<n){
            string len="";
            while(s[i]!='#'){
                len+=s[i];
                i++;
            }
            int length=stoi(len);
            i++;
            ans.push_back(s.substr(i,length));
            i=i+length;
        }
        return ans;
    }
};
