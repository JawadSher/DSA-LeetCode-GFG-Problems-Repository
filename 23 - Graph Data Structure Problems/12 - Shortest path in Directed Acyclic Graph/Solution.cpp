class Solution {
  public:
    // Helper function to perform a topological sort using DFS
    void topologicalSort(int node, vector<int>& visited, stack<int>& Stack, unordered_map<int, list<pair<int, int>>>& adjacencyList) {
        visited[node] = true; // Mark the current node as visited
        
        // Traverse all the neighbors of the current node
        for (auto neighbour : adjacencyList[node]) {
            if (!visited[neighbour.first]) { // If the neighbor is not visited, recursively sort
                topologicalSort(neighbour.first, visited, Stack, adjacencyList);
            }
        }
        
        // Push the current node to the stack after visiting all its neighbors
        Stack.push(node);
    }
    
    // Helper function to calculate the shortest path from the source node
    void getShortestPath(int src, vector<int>& distance, unordered_map<int, list<pair<int, int>>>& adjacencyList, stack<int>& Stack) {
        distance[src] = 0; // Set the source node's distance to 0
        
        // Process nodes in topological order
        while (!Stack.empty()) {
            int currNode = Stack.top(); // Get the current node from the stack
            Stack.pop();
            
            // Update distances to all neighbors if the current node has a valid distance
            if (distance[currNode] != INT_MAX) {
                for (auto neighbour : adjacencyList[currNode]) {
                    int newDistance = distance[currNode] + neighbour.second; // Calculate new distance
                    if (newDistance < distance[neighbour.first]) { // If the new distance is shorter, update it
                        distance[neighbour.first] = newDistance;
                    }
                }
            }
        }
    }
    
    // Main function to find the shortest path in a Directed Acyclic Graph (DAG)
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Create an adjacency list for the graph
        unordered_map<int, list<pair<int, int>>> adjacencyList;
        for (auto edge : edges) {
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];
            adjacencyList[source].push_back({destination, weight}); // Add the edge with weight
        }
        
        // Step 2: Perform a topological sort
        stack<int> Stack; // Stack to store the topological order
        vector<int> visited(V, false); // Visited array to track visited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) { // For unvisited nodes, perform a topological sort
                topologicalSort(i, visited, Stack, adjacencyList);
            }
        }
        
        // Step 3: Calculate shortest paths from the source node
        int src = 0; // Assuming 0 is the source node
        vector<int> distance(V, INT_MAX); // Initialize distances to infinity
        getShortestPath(src, distance, adjacencyList, Stack);
        
        // Step 4: Replace distances that are still INT_MAX with -1 to indicate no path
        for (int& d : distance) {
            if (d == INT_MAX) {
                d = -1;
            }
        }
        
        return distance; // Return the vector containing shortest distances
    }
};
