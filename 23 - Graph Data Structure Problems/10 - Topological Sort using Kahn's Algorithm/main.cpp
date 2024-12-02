#include <bits/stdc++.h>
using namespace std;

// Function to perform Topological Sort using Kahn's Algorithm
void KahnsAlgorithm(vector<vector<int>>& adj, int V) {
    // Step 1: Initialize the indegree array with zeros
    // indegree[i] will store the number of incoming edges to vertex i
    vector<int> indegree(V, 0);

    // Step 2: Create a queue for processing nodes with indegree 0
    queue<int> q;

    // Step 3: Create a vector to store the topological order of nodes
    vector<int> topoOrder;

    // Step 4: Calculate the indegree for all vertices
    for (int i = 0; i < V; i++) {
        for (int neighbour : adj[i]) {
            indegree[neighbour]++; // Increment indegree of each neighbor
        }
    }

    // Step 5: Add all vertices with indegree 0 to the queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i); // Push vertices with no dependencies into the queue
        }
    }

    // Step 6: Process the vertices in the queue one by one
    while (!q.empty()) {
        int node = q.front(); // Get the vertex at the front of the queue
        q.pop(); // Remove it from the queue

        topoOrder.push_back(node); // Add the vertex to the topological order

        // Step 7: For each neighbor of the current vertex
        for (auto neighbour : adj[node]) {
            indegree[neighbour]--; // Decrease the indegree of the neighbor

            // If the indegree of the neighbor becomes 0, add it to the queue
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // Step 8: If the topological order contains all vertices, print it
    if (topoOrder.size() != V) {
        // If the size of the topological order is not equal to the number of vertices
        // it means there was a cycle in the graph, and topological sort is not possible
        cout << "The graph is not a DAG. Topological sort not possible.\n";
        return;
    }

    // Step 9: Output the topological sort
    cout << "Topological sorting of the graph: ";
    for (int node : topoOrder) {
        cout << node + 1 << " "; // Print node numbers (1-based indexing)
    }
    cout << endl;
}

int main() {
    // Step 10: Number of vertices (nodes) in the graph
    int V = 5;

    // Step 11: Define the directed edges of the graph
    // Format: {from, to}
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 5}, {3, 5}, {5, 4}};

    // Step 12: Initialize the adjacency list for the graph
    vector<vector<int>> adj(V);

    // Step 13: Convert the edge list to an adjacency list
    // Adjusting for 0-based indexing
    for (auto i : edges) {
        adj[i[0] - 1].push_back(i[1] - 1);
    }

    // Step 14: Call the Kahn's Algorithm function to perform topological sort
    KahnsAlgorithm(adj, V);

    return 0;
}
