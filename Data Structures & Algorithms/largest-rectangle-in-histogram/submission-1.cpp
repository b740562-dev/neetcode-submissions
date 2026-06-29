class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        // when we need nearest smaller element---monotonically increasing stack !!
        // when we need nearest larger element---monotonically decreasing stack !!

        // A rectangle of height arr[i] can continue as long as the next bars have
        // height >= arr[i]. It ends at the first bar with height < arr[i].

        stack<int> st;
        // our stack will be monotonically increasing 
        int n=arr.size();
        int maxi=0;
        // for stack me bache elements when i reaches n !! we keep our for loop till n
        // we have to check both left and right boundary !!
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n||arr[i]<arr[st.top()])){
                int breadth=arr[st.top()];
                st.pop();
                int length=i;
                if(!st.empty()){
                    length=i-st.top()-1;
                }
                maxi=max(maxi,length*breadth);
            }
            st.push(i);
        }
        return maxi;
    }
};
