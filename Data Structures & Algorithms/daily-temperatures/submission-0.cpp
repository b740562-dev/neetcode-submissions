class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        // indices storing will help !!!
        // we have to find kisi day pe jo temp hai usse jyada temp kitne din bad hota hai !!!

        // we will traverse backward !!!
        // monotonically decreasing stack !!!!
        int n=arr.size();
        vector<int> ans(n);
        ans[n-1]=0;
        stack<int> st;
        st.push(n-1);


        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};
