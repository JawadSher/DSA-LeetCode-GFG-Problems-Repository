class Solution {
public:
    // Depth-First Search (DFS) function to explore the graph
    void dfs(int node, int parent, int timer, int& result, vector<int>& visited, vector<int>& disc, vector<int>& low, vector<vector<int>>& adjacencyList, int c, int d){
        visited[node] = true;                  // Mark the current node as visited
        disc[node] = low[node] = timer++;     // Set discovery time and low time of the node
        
        // Traverse all adjacent vertices (neighbors) of the current node
        for(int vertex : adjacencyList[node]){
            if(vertex == parent) continue;     // Skip the parent node to avoid going backward in the DFS

            if(!visited[vertex]){              // If the neighbor is unvisited, perform DFS on it
                dfs(vertex, node, timer, result, visited, disc, low, adjacencyList, c, d);
                low[node] = min(low[node], low[vertex]); // Update the low time of the current node
                
                // If low value of the neighbor is greater than the discovery time of the current node
                // and the edge (node, vertex) is the target edge (c, d), set result to 1 (indicating it's a bridge)
                if(low[vertex] > disc[node] && ((node == c && vertex == d) || (node == d && vertex == c))) 
                    result = 1;
            } else {
                low[node] = min(low[node], disc[vertex]); // Update the low time if the neighbor is already visited
            }
        }
    }
    
    // Function to check if the edge (c, d) is a bridge
    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<int> disc(V, -1); // Discovery time for each vertex (initially -1, indicating unvisited)
        vector<int> low(V, -1);  // Lowest discovery time reachable from the vertex (initially -1)
        vector<int> visited(V, false); // To keep track of visited nodes
        int result = 0; // Variable to store the result (0 means no bridge, 1 means it's a bridge)
        
        vector<vector<int>> adjacencyList(V); // Adjacency list to represent the graph
        
        // Build the adjacency list from the given edge list
        for(int i = 0; i < V; i++){
            for(auto& vertex : adj[i]){
                adjacencyList[i].push_back(vertex);
            }
        }
        
        // Perform DFS from every unvisited node
        for(int i = 0; i < V; i++) 
            if(!visited[i]) 
                dfs(i, -1, 0, result, visited, disc, low, adjacencyList, c, d);
        
        return result; // Return 1 if the edge (c, d) is a bridge, else return 0
    }
};
