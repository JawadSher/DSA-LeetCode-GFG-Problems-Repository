class Solution {
  private:
    bool knows(vector<vector<int>> & mat, int a, int b){
        if(mat[a][b] == 1) return true;
        
        return false;
    }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        stack<int> st;
        
        int n = mat.size();
        
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(knows(mat, a, b)){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        
        int candidate = st.top();
        
        bool rowCheck = true;
        for(int i = 0; i < n; i++){
            if(mat[candidate][i] == 1){
                rowCheck = false;
                break;
            }
        }
        
        
        bool colCheck = true;
        for(int i = 0; i < n; i++){
            if(i != candidate && mat[i][candidate] == 0){
                colCheck = false;
                break;
            }
        }
        
        
        if(rowCheck && colCheck) return candidate;
        
        return -1;
    }
};
