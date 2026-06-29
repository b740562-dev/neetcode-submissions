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
        int row=0, col=n-1;
        while(row<m && col>=0){
            if(matrix[row][col]==target){
                return 1;
            }
            else if(matrix[row][col]<target){
                row++;
            }
            else{
                col--;
            }
        }
        return 0;

        // q wants O(log(mn))---so we will do :
        // see this 2d matrix is acting like a flattend array where all elements are sorted !!!

        
    }
};
