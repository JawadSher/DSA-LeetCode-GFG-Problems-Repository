class Solution {
  public:
    bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, vector<vector<int>>& adj){
        visited[node] = true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cycleDetected = isCycleDFS(neighbour, node, visited, adj);
                if(cycleDetected) return true;
            }else if(neighbour != parent) return true;
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        
        unordered_map<int, bool> visited;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bool ans = isCycleDFS(i, -1, visited, adj);
                if(ans == 1) return true;
            }
        }
        
        
        return false;
    }
};
