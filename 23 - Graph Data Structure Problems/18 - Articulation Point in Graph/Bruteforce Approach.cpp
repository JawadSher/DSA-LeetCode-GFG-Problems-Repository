class Solution {
public:
    // Helper function to perform DFS
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjacencyList) {
        visited[node] = true;
        for (auto neighbour : adjacencyList[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited, adjacencyList);
            }
        }
    }

    // Function to find articulation points using brute force
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> AP; // To store articulation points
        vector<vector<int>> adjacencyList(V);
        
        // Convert adj[] to a vector of vectors
        for (int i = 0; i < V; i++) {
            for (auto neighbour : adj[i]) {
                adjacencyList[i].push_back(neighbour);
            }
        }
        
        // Check each node as a potential articulation point
        for (int i = 0; i < V; i++) {
            vector<int> visited(V, false); // Visited array
            // Temporarily remove node `i` from the graph
            vector<vector<int>> tempAdjList = adjacencyList;
            for (auto& neighbours : tempAdjList) {
                neighbours.erase(remove(neighbours.begin(), neighbours.end(), i), neighbours.end());
            }
            
            // Perform DFS from a node other than `i`
            int startNode = (i == 0) ? 1 : 0;
            dfs(startNode, visited, tempAdjList);
            
            // Check if any node is not visited
            bool isDisconnected = false;
            for (int j = 0; j < V; j++) {
                if (j != i && !visited[j]) {
                    isDisconnected = true;
                    break;
                }
            }
            
            // If the graph becomes disconnected, `i` is an articulation point
            if (isDisconnected) {
                AP.push_back(i);
            }
        }
        
        // If no articulation points found, return {-1}
        if (AP.empty()) {
            AP.push_back(-1);
        } else {
            sort(AP.begin(), AP.end());
        }
        
        return AP;
    }
};
