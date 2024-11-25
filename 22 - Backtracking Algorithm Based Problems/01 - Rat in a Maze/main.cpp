class Solution {
  public:
    bool isSafe(int newX, int newY, vector<vector<bool>>& vis,  vector<vector<int>>& arr, int n){
        
        if((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && vis[newX][newY] != 1 && arr [newX][newY] == 1) return true;
        
        return false;
    }
    
    void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& vis, string path){
        
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        vis[x][y] = 1;
        
        if(isSafe(x+1, y, vis, arr, n)){
            solve(x+1, y, arr, n, ans, vis, path + 'D');
        }
        
        if(isSafe(x, y-1, vis, arr, n)){
            solve(x, y-1, arr, n, ans, vis, path + 'L');

        }
        
        if(isSafe(x, y+1, vis, arr, n)){
            solve(x, y+1, arr, n, ans, vis, path + 'R');
        }
        
        if(isSafe(x-1, y, vis, arr, n)){
            solve(x-1, y, arr, n, ans, vis, path + 'U');
        }
        
        vis[x][y] = 0;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat.size(), 0));
        
        string path = "";
        
        solve(0, 0, mat, mat.size(), ans, visited, path);
        
        return ans;
    }
};
