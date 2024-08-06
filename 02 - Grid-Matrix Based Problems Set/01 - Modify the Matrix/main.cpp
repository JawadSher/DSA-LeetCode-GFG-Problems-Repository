class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> maxColumn(n, INT_MIN);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxColumn[j] = max(maxColumn[j], matrix[i][j]);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = maxColumn[j];
                }
            }
        }

    return matrix;
    }
};
