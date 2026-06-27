class Solution {
private:
    vector<int> suffixmax(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n,0);
        int suffix=arr[n-1];
        for(int i=n-1;i>=0;i--){
            if(arr[i]>suffix){
                ans[i]=arr[i];
                suffix=arr[i];
            }
            else{
                ans[i]=suffix;
            }
        }
        return ans;
    }
public:
    int trap(vector<int>& arr) {
        // see for each index we can calculate how much water can be trapped on top of it !!!
        // at each index water we can trap is min(leftmax,rightmax)-arr[index]!!!
        // summing for all the indexes gives the final ans !!!!!
        // int n=arr.size(),total=0;
        // vector<int> rightmax=suffixmax(arr);
        // int leftmax=arr[0];
        // for(int i=0;i<n;i++){
        //     if(arr[i]>leftmax){
        //         leftmax=arr[i];
        //     }
        //     total+=min(leftmax,rightmax[i])-arr[i];
        // }
        // return total;

        // ---------------------------------OPTIMAL-------------------------------------------------------

        // optimal approach is to use sliding window !!!

        // int l=0, r=arr.size()-1,total=0;
        // int leftmax=0, rightmax=0;
        // while(l<r){
        //     if(arr[l]<=arr[r]){
        //         if(arr[l]<leftmax){
        //             total+=leftmax-arr[l];
        //         }
        //         else{
        //             leftmax=arr[l];
        //         }
        //         l++;
        //     }
        //     else{
        //         if(arr[r]<rightmax){
        //             total+=rightmax-arr[r];
        //         }
        //         else{
        //             rightmax=arr[r];
        //         }
        //         r--;
        //     }
        // }
        // return total;


        // ---------------------------using monotonic stack-------------------------------------------------
        int n=arr.size();
        // atleast 3 buildings needed to store water !!!!
        if(n<=2){
            return 0;
        }

        // see i have to find left and right boundary !!!
        // whenevr we encounter an element that's greater than what is stored in st.top() then it will be right boundary !!

        // we will be having monotonically decreasing stack !!!!
        
        // monotonic stack will store indices not height---for breadth calculation!!!
        stack<int> st;

        // it calculates water storage horizontally not vertically !!!!

        int total=0;

        for(int i=0;i<n;i++){
            // stack empty nhi hai to left boundary is pkka se present --- need to think of right boundary !!
            // jab tak arr[i] top se bada hai we are getting our right boundary !!!
            while(!st.empty() && arr[i]>arr[st.top()]){
                int curr=st.top();
                st.pop();

                // for i=1 removing i=0 will make stack empty 
                if(st.empty()){
                    break;
                }

                // abhi top pe jo element hai that is left boudnary 
                int length=min(arr[st.top()],arr[i])-arr[curr];
                // one index will capture for all !!!!
                int breadth=i-st.top()-1;
                total+=length*breadth;
            }
            st.push(i);
            
        }
        return total;
    }
};
