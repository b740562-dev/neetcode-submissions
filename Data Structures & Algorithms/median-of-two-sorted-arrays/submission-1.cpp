class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        // BS will be applied on how many elements of arr1 to pick!!!---for arr1 smaller array

        int n1=arr1.size(), n2=arr2.size();
        if(n2<n1){
            return findMedianSortedArrays(arr2,arr1);
        }
        int n=n1+n2;
        int lefthalf;

        // take care of operator precedence
        lefthalf=(n1+n2+1)/2;

        // agar lefthalf me n1 se kam elements chahiye then high=lefthalf !!!
        // agar lefthalf me n2 se jyada elements chahiye then hme n1 se elements uthane hi pdenge !!!

        int low=max(0,lefthalf-n2);
        int high=min(n1,lefthalf);

        while(low<=high){
            int mid=low+(high-low)/2;
            // how many elements of n2 in left half
            int remain=lefthalf-mid;

            // their are possibilities of out of bound of mid as mid can be n1---if mid 0 then mid-1 OOB !!
            // we need 4 elements l1,l2,r1,r2 !!!
            int l1=(mid==0)?INT_MIN:arr1[mid-1];
            int r1=(mid==n1)?INT_MAX:arr1[mid];
            int l2=(remain==0)?INT_MIN:arr2[remain-1];
            int r2=(remain==n2)?INT_MAX:arr2[remain];
            if(l1<=r2 && l2<=r1){
                if(n%2!=0){
                    return max(l1,l2);
                }
                double left=max(l1,l2);
                double right=min(r1,r2);
                // care about operator precedence !!!!
                return (left+right)/2.0;
            }
            else if(l1>r2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};
