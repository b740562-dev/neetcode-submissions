class Solution {
public:

    string encode(vector<string>& strs) {
        // we will keep length as a limiter and # as a delimiter !!!
        string res="";
        for(string s:strs){
            // to_string !!!!!!
            res+=to_string(s.size())+'#'+s;
        }
        return res;
    }

    vector<string> decode(string s) {

        vector<string> res;
        
        int i=0, n=s.size();

        while(i<n){
            // lenth of a string can be 12. So, storage in one index i only is not possible !!!
            // example 12#abcdefghijkl3#abc----we can't assume string len can be represented 
            // by a single character

            // keep i at len find where the delimiter is present call delimiter position j 
            // before j we will length !!!

            int j=i+1;
            while(s[j]!='#'){
                j++;
            }

            // from i to j-i-1 everything is length

            // remember str to int conversion needs usage of stoi !!!

            // s.substr needs two inputs---strat index and length from start index !!!
            int stringlen=stoi(s.substr(i,j-i));
            res.push_back(s.substr(j+1,stringlen));
            i=j+1+stringlen;
        }
        return res;
    }
};
