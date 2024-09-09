class Solution {
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int r_index = 0;
        int c_index = cols - 1;

        while(r_index < rows && c_index >= 0){
            int element = matrix[r_index][c_index];

            if(element == target){
                return true;
            }else if(element < target || element < matrix[r_index][0]){
                r_index++;
            }else if(element > target || element <= matrix[r_index][cols-1]){
                c_index--;
            }
        }

        return false;
    }
};
