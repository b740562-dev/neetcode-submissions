class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        // indices storing will help !!!
        // we have to find kisi day pe jo temp hai usse jyada temp kitne din bad hota hai !!!

        // we will traverse backward !!!
        // monotonically decreasing stack !!!!
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            // always add edge cases when writing while loop !!!
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
