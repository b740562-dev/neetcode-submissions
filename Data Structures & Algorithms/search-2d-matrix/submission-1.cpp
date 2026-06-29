class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // one solution can be in mlogn 
        int m=matrix.size(), n=matrix[0].size();

        for(int i=0;i<m;i++){
            int lb=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            if(lb!=n && matrix[i][lb]==target){
                return 1;
            }
        }

        return 0;

    }
};
