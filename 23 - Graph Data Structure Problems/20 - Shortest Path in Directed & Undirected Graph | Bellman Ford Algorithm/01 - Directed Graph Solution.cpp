class Solution {
  public:
    /* Function to implement Bellman-Ford Algorithm
     * Parameters:
     * V: Number of vertices in the graph
     * edges: A vector of vectors where each sub-vector represents an edge in the format [source, destination, weight]
     * src: Source vertex from which shortest distances are calculated
     * Returns:
     * A vector of shortest distances from the source to all vertices. 
     * If a negative-weight cycle is detected, returns [-1].
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Step 1: Initialize the distances to all vertices as a very large number (infinity)
        // Use 100000000 as the value for "infinity" as per the problem constraints
        int n = 100000000;
        vector<int> distance(V, n); // Distance array initialized to "infinity"
        distance[src] = 0; // Distance to the source vertex is 0

        // Step 2: Relax all edges (V-1) times
        // Iterate (V-1) times because the shortest path in a graph with V vertices can have at most (V-1) edges
        for (int i = 0; i < V - 1; i++) {
            // Traverse through all edges
            for (auto edge : edges) {
                int source = edge[0];       // Source vertex of the edge
                int destination = edge[1]; // Destination vertex of the edge
                int weight = edge[2];      // Weight of the edge

                // Relax the edge if the source distance is not infinity and the new path is shorter
                if (distance[source] != n && (distance[source] + weight < distance[destination])) {
                    distance[destination] = distance[source] + weight; // Update the shortest distance
                }
            }
        }

        // Step 3: Check for negative-weight cycles
        // A negative-weight cycle exists if we can still relax any edge after (V-1) iterations
        for (auto edge : edges) {
            int source = edge[0];       // Source vertex of the edge
            int destination = edge[1]; // Destination vertex of the edge
            int weight = edge[2];      // Weight of the edge

            // If the edge can still be relaxed, a negative-weight cycle exists
            if (distance[source] != n && (distance[source] + weight < distance[destination])) {
                return vector<int>(1, -1); // Return [-1] to indicate a negative-weight cycle
            }
        }

        // Step 4: Return the calculated shortest distances from the source vertex
        return distance;
    }
};
