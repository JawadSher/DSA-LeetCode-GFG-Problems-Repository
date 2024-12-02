class Solution {
  public:
    /* Function to implement Bellman-Ford Algorithm for an undirected graph
     * Parameters:
     * V: Number of vertices in the graph
     * edges: A vector of vectors where each sub-vector represents an edge in the format [source, destination, weight]
     * src: Source vertex from which shortest distances are calculated
     * Returns:
     * A vector of shortest distances from the source to all vertices. 
     * If a negative-weight cycle is detected, returns [-1].
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int n = 100000000; // Representing infinity
        vector<int> distance(V, n); // Distance array initialized to "infinity"
        distance[src] = 0; // Distance to the source vertex is 0

        // Step 1: Preprocess the edges to handle the undirected graph
        vector<vector<int>> undirectedEdges;
        for (auto edge : edges) {
            // Add both directions for the undirected graph
            undirectedEdges.push_back({edge[0], edge[1], edge[2]}); // (u -> v)
            undirectedEdges.push_back({edge[1], edge[0], edge[2]}); // (v -> u)
        }

        // Step 2: Relax all edges (V-1) times
        for (int i = 0; i < V - 1; i++) {
            for (auto edge : undirectedEdges) {
                int source = edge[0];
                int destination = edge[1];
                int weight = edge[2];

                // Relax the edge if the source distance is not infinity and the new path is shorter
                if (distance[source] != n && (distance[source] + weight < distance[destination])) {
                    distance[destination] = distance[source] + weight;
                }
            }
        }

        // Step 3: Check for negative-weight cycles
        for (auto edge : undirectedEdges) {
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];

            // If the edge can still be relaxed, a negative-weight cycle exists
            if (distance[source] != n && (distance[source] + weight < distance[destination])) {
                return vector<int>(1, -1); // Return [-1] to indicate a negative-weight cycle
            }
        }

        // Step 4: Return the calculated shortest distances from the source vertex
        return distance;
    }
};
