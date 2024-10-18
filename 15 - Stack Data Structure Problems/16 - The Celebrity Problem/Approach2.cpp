class Solution {
    
  private:
    bool knows(vector<vector<int>>& mat, int a, int b){
        if(mat[a][b] == 1) return true;
        
        return false;
    }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        
        for(int i = 0; i < n; i++){
            bool isCelebrity = true;
            
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(knows(mat, i, j) || !knows(mat, j, i)){
                        isCelebrity = false;
                        break;
                    }
                }
            }
            
            if(isCelebrity) return i;
        }
        
        return -1;
    }
};
