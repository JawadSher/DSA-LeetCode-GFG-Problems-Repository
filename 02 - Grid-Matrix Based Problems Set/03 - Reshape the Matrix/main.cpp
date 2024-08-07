class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int original_rows = mat.size();
        int original_cols = mat[0].size();

        if(original_rows * original_cols != r * c){
            return mat;
        }

        vector<int> mat_values;
        vector<vector<int>> reshapedMat(r, vector<int>(c));

        for(int i = 0; i < original_rows; i++){

            for(int j = 0; j < original_cols; j++){
                mat_values.push_back(mat[i][j]);
            }
        }


        for(int i = 0; i < r; i++){

            for(int j = 0; j < c; j++){
                reshapedMat[i][j] = mat_values[i * c + j];
            }
        }


    return reshapedMat;
    }
};
