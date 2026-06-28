class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack() {}
    
    void push(int val) {
        // see the problem is if top is the mini element then during pop operation we have to ensure 
        // that we have prevmini stored with us !!!---can either use pair or a smart shortcut is that 
        // store in top 2*val-prevmini !!! 
        if(st.empty() || val<st.top().second){
            st.push({val,val});
        }
        else{
            st.push({val,st.top().second});
        }
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
