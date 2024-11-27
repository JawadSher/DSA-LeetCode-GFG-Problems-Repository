class Solution {
  public:
    bool isCycleBFS(int src, unordered_map<int, bool> &visited, vector<vector<int>>& adj){
        unordered_map<int, int> parent;
        
        parent[src] = -1;
        visited[src] = true;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto neighbour : adj[front]){
                if(visited[neighbour] == true && neighbour != parent[front]) return true;
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        
        unordered_map<int, bool> visited;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bool ans = isCycleBFS(i, visited, adj);
                if(ans == 1) return true;
            }
        }
        
        
        return false;
    }
};
