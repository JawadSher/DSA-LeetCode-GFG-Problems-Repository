class Solution {
public:
    // Helper function to perform DFS traversal and find critical connections
    void DFS(int server, int timer, int parentServer, vector<int>& low, vector<int>& disc, vector<int>& visited, vector<vector<int>>& criticalEdge, vector<vector<int>>& connections){

        // Mark the current server as visited
        visited[server] = true;

        // Set discovery time and lowest reachable time for the current server
        disc[server] = low[server] = timer++; // timer is incremented after setting the discovery time
        
        // Explore all neighboring servers (connections)
        for(int & neighbourServer : connections[server]){
            
            // Skip the parent server to avoid going back to the parent in the DFS tree
            if(neighbourServer == parentServer) continue;

            // If the neighboring server is not visited, explore it
            if(!visited[neighbourServer]){
                DFS(neighbourServer, timer, server, low, disc, visited, criticalEdge, connections);

                // After visiting the neighbor, update the low time for the current server
                low[server] = min(low[server], low[neighbourServer]);

                // If the lowest time of the neighbor is greater than the discovery time of the current server,
                // it indicates that the edge between current server and the neighbor is a critical connection.
                if(low[neighbourServer] > disc[server]) 
                    criticalEdge.push_back({server, neighbourServer});
            }else {
                // If the neighboring server was already visited, update the low time
                low[server] = min(low[server], low[neighbourServer]);
            }
        }
    }

    // Main function to find all critical connections in the network
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Arrays to store the lowest time reachable from a server and the discovery time of each server
        vector<int> low(n, -1);
        vector<int> disc(n, -1);
        
        // Array to track if a server has been visited
        vector<int> visited(n, false);

        // To store the critical connections (edges)
        vector<vector<int>> criticalEdge;

        // Adjacency list to represent the network of servers
        vector<vector<int>> adjacencyList(n);
        
        // Build the adjacency list from the connections
        for(auto& edge : connections){
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // Start DFS from each server that hasn't been visited
        for(int i = 0; i < n; i++) 
            if(!visited[i]) 
                DFS(i, 0, -1, low, disc, visited, criticalEdge, adjacencyList);

        // Return the list of critical connections (edges)
        return criticalEdge;
    }
};
