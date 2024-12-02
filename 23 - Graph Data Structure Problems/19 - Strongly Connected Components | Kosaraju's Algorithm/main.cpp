class Solution
{
    public:
    // Function to perform Depth First Search (DFS) and populate the stack with nodes in order of their finish time
    void DFS(int node, vector<int>& visited, vector<vector<int>>& adjacencyList, stack<int>& nodesOrder) {
        // Mark the current node as visited
        visited[node] = true;
        
        // Explore all unvisited neighbors of the current node
        for (auto neighbour : adjacencyList[node]) {
            if (!visited[neighbour]) 
                DFS(neighbour, visited, adjacencyList, nodesOrder);
        }
        
        // After visiting all neighbors, push the current node onto the stack
        nodesOrder.push(node);
    }
    
    // Function to perform DFS on the transposed graph
    void reverseDFS(int node, vector<vector<int>>& adjacencyList, vector<int>& visited) {
        // Mark the current node as visited
        visited[node] = true;
        
        // Explore all unvisited neighbors of the current node in the transposed graph
        for (auto neighbour : adjacencyList[node]) {
            if (!visited[neighbour]) 
                reverseDFS(neighbour, adjacencyList, visited);
        }
    }
    
    // Function to find the number of strongly connected components (SCCs) using Kosaraju's Algorithm
    int kosaraju(int V, vector<vector<int>>& adj) {
        // Step 1: Initialize visited vector and stack to store nodes in order of their finish time
        vector<int> visited(V, false);
        stack<int> nodesOrder;
        vector<vector<int>> transpose(V); // Adjacency list for the transposed graph
        int totalSCCs = 0; // Counter for SCCs
        
        // Step 2: Perform DFS on the original graph to populate the stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) 
                DFS(i, visited, adj, nodesOrder);
        }
        
        // Step 3: Create the transposed graph
        for (int i = 0; i < V; i++) {
            for (auto neighbour : adj[i]) {
                // Reverse the direction of edges
                transpose[neighbour].push_back(i);
            }
        }
        
        // Step 4: Reset visited array for use in the second DFS
        fill(visited.begin(), visited.end(), false);
        
        // Step 5: Perform DFS on the transposed graph in the order of nodes in the stack
        while (!nodesOrder.empty()) {
            int node = nodesOrder.top();
            nodesOrder.pop();
            
            // If the node is not visited, it means we've found a new SCC
            if (!visited[node]) {
                totalSCCs++; // Increment SCC count
                reverseDFS(node, transpose, visited); // Explore all nodes in this SCC
            }
        }
        
        // Step 6: Return the total number of SCCs
        return totalSCCs;
    }
};
