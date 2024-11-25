class Solution {
  public:
    void dfsUtil(int node, vector<vector<int>>& adj, unordered_map<int, bool>& visited, vector<int>& result){
        visited[node] = true;
        result.push_back(node);
        
        for(int neighbor : adj[node]){
            if(!visited[neighbor]) dfsUtil(neighbor, adj, visited, result);
        }
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();
        unordered_map<int, bool> visited;
        vector<int> result;
        
        dfsUtil(0, adj, visited, result);
        return result;
    }
};
