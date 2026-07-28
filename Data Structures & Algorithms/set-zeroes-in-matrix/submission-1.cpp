class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m=matrix.size(), n=matrix[0].size();
        int firstrow=0, firstcol=0;

        // check if any element of first row or first col is 0 !!!
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                firstrow=1;
                break;
            }
        }

        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                firstcol=1;
                break;
            }
        }
        
        // check if any element from 1 to m or 1 to n is zero then set it's [r][0]=0 and [0][c]=0 !!! 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // mark corresponding elements = 0!!! 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        // if first row is flagged---set entire first row to 0 !!!
        if(firstrow){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }

        if(firstcol){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }


    }
};
