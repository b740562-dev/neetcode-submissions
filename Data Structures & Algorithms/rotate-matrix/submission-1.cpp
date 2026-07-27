class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // we have to do in place ---- transpose the matrix and reverse the row
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
