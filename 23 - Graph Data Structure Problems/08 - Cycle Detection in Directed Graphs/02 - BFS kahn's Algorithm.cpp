class Solution {
  public:
    bool isDFSCycle(int node, vector<vector<int>>& adj, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cycleDetected = isDFSCycle(neighbour, adj, visited, dfsVisited);
                if(cycleDetected) return true;
            }else if(dfsVisited[neighbour]) return true;
        }
        
        dfsVisited[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool ans = isDFSCycle(i, adj, visited, dfsVisited);
                if(ans == true) return true;
            }
        }
        
        return false;
    }
};
