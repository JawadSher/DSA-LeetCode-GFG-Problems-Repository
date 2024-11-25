class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> result;
        vector<bool> visited(V, false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
            
            result.push_back(currentNode);
            
            for(int neighbor : adj[currentNode]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        return result;
        
    }
};
