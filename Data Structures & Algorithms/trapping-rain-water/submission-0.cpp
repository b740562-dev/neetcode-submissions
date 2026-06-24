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
        int n=arr.size(),total=0;
        vector<int> rightmax=suffixmax(arr);
        int leftmax=arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]>leftmax){
                leftmax=arr[i];
            }
            total+=min(leftmax,rightmax[i])-arr[i];
        }
        return total;
    }
};
