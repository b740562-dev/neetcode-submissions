class Solution {
public:
    int findMin(vector<int> &arr) {
        // always there will be one sorted half and one unsorted half !!!
        int mini=1e9, n=arr.size();
        int low=0, high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]<=arr[mid]){
                // left half is sorted !!
                mini=min(mini,arr[low]);
                low=mid+1;
            }
            else{
                // left half is sorted !!
                mini=min(mini,arr[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};
