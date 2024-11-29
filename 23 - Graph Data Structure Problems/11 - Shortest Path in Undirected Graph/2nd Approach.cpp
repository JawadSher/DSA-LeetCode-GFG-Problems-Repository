#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Step 1: Create adjacency list to represent the graph
        vector<vector<int>> adj(N);
        // Build the adjacency list from the edges
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];  // Start vertex of the edge
            int v = edges[i][1];  // End vertex of the edge
            adj[u].push_back(v);  // Add v as a neighbor of u
            adj[v].push_back(u);  // Add u as a neighbor of v (since the graph is undirected)
        }

        // Step 2: Initialize visited and parent vectors
        // visited[i] will be true if node i is visited
        vector<bool> visited(N, false);  
        // parent[i] will store the previous node of i in the shortest path
        vector<int> parent(N, -1);  

        // Step 3: Perform BFS traversal from the source node
        queue<int> q;
        q.push(src);         // Add the source node to the queue
        visited[src] = true; // Mark the source node as visited

        // Step 4: BFS to explore all nodes and find the shortest path
        while (!q.empty()) {
            int node = q.front(); // Get the front node from the queue
            q.pop();              // Remove the front node from the queue

            // Step 5: Explore all neighbors of the current node
            for (auto i : adj[node]) {
                // If the neighbor hasn't been visited, mark it as visited
                if (!visited[i]) {
                    visited[i] = true;    // Mark the neighbor as visited
                    parent[i] = node;     // Set the parent of the neighbor
                    q.push(i);             // Add the neighbor to the queue for further exploration
                }
            }
        }

        // Step 6: If the destination (M) is not reachable, return {-1}
        if (!visited[M]) {
            return {-1};  // If destination node M is not visited, no path exists
        }

        // Step 7: Reconstruct the path from source to destination
        vector<int> ans;
        int currentNode = M;  // Start from the destination node
        while (currentNode != src) {
            ans.push_back(currentNode);  // Add the current node to the path
            currentNode = parent[currentNode];  // Move to the parent node
        }
        ans.push_back(src);  // Add the source node to the path

        // Step 8: Reverse the path to make it from source to destination
        reverse(ans.begin(), ans.end());  // Reverse the path to get it from src to M
        return ans;  // Return the path
    }
};

int main() {
    int N = 9, M = 4; // Number of nodes (N) and the destination node (M)
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
        {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };
    int src = 0; // Starting node

    Solution sol;
    // Call the function to find the shortest path from src to M
    vector<int> result = sol.shortestPath(edges, N, M, src);

    // Step 9: Output the result
    if (result.size() == 1 && result[0] == -1) {
        cout << "No path exists" << endl;  // No path found from src to M
    } else {
        cout << "Shortest path from " << src << " to " << M << ": ";
        // Print the nodes in the shortest path
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
