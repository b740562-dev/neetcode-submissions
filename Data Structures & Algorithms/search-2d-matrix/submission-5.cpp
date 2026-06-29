class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // one solution can be in mlogn 
        int m=matrix.size(), n=matrix[0].size();

        // for(int i=0;i<m;i++){
        //     int lb=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
        //     if(lb!=n && matrix[i][lb]==target){
        //         return 1;
        //     }
        // }
        // above solution was O(m*logn) and we want O(log(m*n)) :

        // below is my staircase approach which runs in O(m+n) time 
        // int row=0, col=n-1;
        // while(row<m && col>=0){
        //     if(matrix[row][col]==target){
        //         return 1;
        //     }
        //     else if(matrix[row][col]<target){
        //         row++;
        //     }
        //     else{
        //         col--;
        //     }
        // }
        // return 0;

        // q wants O(log(mn))---so we will do :
        // see this 2d matrix is acting like a flattend array where elements are completely 
        // sorted !!!

        // one approach is to apply BS in every row then every col of that row 
        // logm + logn = log(mn)

        int lowr=0, highr=m-1;
        int ans=0;
        while(lowr<=highr){
            int mid=lowr+(highr-lowr)/2;
            // always first write = condition !!!
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                ans=mid;
                break;
            }
            else if(matrix[mid][0]>target){
                highr=mid-1;
            }
            else{
                lowr=mid+1;
            }
            // curr row contains the element !!
        }

        if(lowr>highr){
            return 0;
        }
        else {
            int lowc=0, highc=n-1;
       
        while(lowc<=highc){
            int mid2=lowc+(highc-lowc)/2;
            if(matrix[ans][mid2]==target){
                return 1;
            }
            if(matrix[ans][mid2]>target){
                highc=mid2-1;
            }
            else{
                lowc=mid2+1;
            }
        }
        }
        return 0;
    }
};
