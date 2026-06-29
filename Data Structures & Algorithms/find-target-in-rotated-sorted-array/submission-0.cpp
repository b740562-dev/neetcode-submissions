class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0, high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(target==arr[mid]){
                return mid;
            }
            if(arr[low]<=arr[mid]){
                // left half is sorted !!
                if(target<arr[mid] && target>=arr[low]){
                    // target is present in left half 
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                // right half is sorted !!
                if(target>arr[mid] && target<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
