class Solution {
  private:
    bool isSafe(int x, int y , int n, int m, vector<vector<int>> &visited, vector<vector<int>> &mat){
        if((x >= 0 && x < n) && (y >= 0 && y < m) && visited[x][y] == 0 && mat[x][y] == 1){
            return true;
        }
        
        
        return false;
    }
    void solve(vector<vector<int>> &mat, int n, int m, int x, int y, vector<vector<int>> visited, string path, vector<string> &answer){
        
        // base case
        if(x == n-1 && y == m-1){
            answer.push_back(path);
            
            return;
        }
        
        visited[x][y] = 1;
        
        // down
        int newx = x+1;
        int newy = y;
        
        if(isSafe(newx, newy, n, m, visited, mat)){
            path.push_back('D');
            solve(mat, n, m, newx, newy, visited, path, answer);
            path.pop_back();
        }
        
        
        // left
        newx = x;
        newy = y-1;
        
         if(isSafe(newx, newy, n, m, visited, mat)){
            path.push_back('L');
            solve(mat, n, m, newx, newy, visited, path, answer);
            path.pop_back();
        }
        
        // right
        newx = x;
        newy = y+1;
        
         if(isSafe(newx, newy, n, m, visited, mat)){
            path.push_back('R');
            solve(mat, n, m, newx, newy, visited, path, answer);
            path.pop_back();
        }
        
        // Up
        newx = x-1;
        newy = y;
        
         if(isSafe(newx, newy, n, m, visited, mat)){
            path.push_back('U');
            solve(mat, n, m, newx, newy, visited, path, answer);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> answer;
        
        if(mat[0][0] == 0) return answer;
        
        int srcx = 0;
        int srcy = 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        
        string path = "";
        solve(mat, n, m, srcx, srcy, visited, path, answer);
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};
