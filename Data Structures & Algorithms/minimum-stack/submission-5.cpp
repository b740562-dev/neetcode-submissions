class MinStack {
private:
// without using pair !!!
    // stack<pair<int,int>> st;
    stack<long long> st;
    long long mini=1e9;
public:
    MinStack() {}
    
    void push(int val) {
        // see the problem is if top is the mini element then during pop operation we have to ensure 
        // that we have prevmini stored with us !!!---can either use pair or a smart shortcut is that 
        // store in top 2*val-prevmini !!! 
        // this modified value is always lesser than val !!!
        // proved using val-mini<0 add val to both side !!!

        if(st.empty() || val>=mini){
            if(st.empty()){
                mini=val;
            }
            st.push(val);
        }
        else{
            st.push(2*(long long)val-mini);
            mini=val;
        }
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }
        if(st.top()<mini){
            // modified value is stored !!
            // top wala element he minimum tha !!!
            mini=2*mini-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        if(st.top()<mini){
            // modified one !!
            return (int)mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};
