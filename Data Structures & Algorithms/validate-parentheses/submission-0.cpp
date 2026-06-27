class Solution {
public:
    bool isValid(string s) {
        // open bracket aate ja rha to tikh hai----closing bracket hmesa last in ka phele aana chahiye !!!
        // stack empty ho jana chahiye !!!

        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i<n && s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }

            // agar stack me open brackets push nhi hue and u got a closing bracket 
            else{
                if(st.empty()){
                    return 0;
                }
                if((st.top()=='('&& s[i]==')')|| (st.top()=='{'&& s[i]=='}') || (st.top()=='['&& s[i]==']')){
                    st.pop();
                }
                else{
                    return 0;
                }
            }
        }
        return st.empty();
    }
};
