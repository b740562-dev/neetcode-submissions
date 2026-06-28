#include<bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& arr) {
        // in RPN arr will never contain only two elements because operands is always followed by 
        // their operators !!!
        int n=arr.size();
        
        stack<int> st;

        // all the operations will always be done among 2 elements !!!

        for(int i=0;i<n;i++){
            if(arr[i]=="+"||arr[i]=="-"||arr[i]=="*"||arr[i]=="/"){
                int k1=st.top();
                st.pop();
                int k2=st.top();
                st.pop();
                if(arr[i]=="+"){
                    st.push(k1+k2);
                }
                else if(arr[i]=="-"){
                    st.push(k2-k1);
                }
                else if(arr[i]=="*"){
                    st.push(k1*k2);
                }
                else{
                    st.push(k2/k1);
                }
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
    }
};
