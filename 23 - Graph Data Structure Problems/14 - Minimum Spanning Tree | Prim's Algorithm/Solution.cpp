class Solution
{
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree (MST)
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Create a vector to track if a node is included in the MST (initialized to false)
        vector<int> MST(V, false);

        // Create a priority queue (min-heap) to store edges, 
        // where each element is a pair: (weight, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Variable to store the total weight of the MST
        int totalWeight = 0;
        
        // Push the first node (0th vertex) with weight 0 into the priority queue to start from
        pq.push({0, 0});
        
        // While there are still nodes to be processed
        while (!pq.empty()) {
            // Get the edge with the minimum weight (top of the priority queue)
            pair<int, int> top = pq.top();
            pq.pop();
            
            // Extract the weight and node from the pair
            int weight = top.first;
            int node = top.second;
            
            // If the node is already included in MST, skip it
            if (MST[node]) continue;
            
            // Mark the current node as included in the MST
            MST[node] = true;
            
            // Add the weight of the current edge to the total MST weight
            totalWeight += weight;
            
            // Explore all adjacent nodes (neighbors) of the current node
            for (auto &edge : adj[node]) {
                int vertex = edge[0];  // Get the adjacent vertex
                int vertexWeight = edge[1];  // Get the weight of the edge to the adjacent vertex
                
                // If the adjacent vertex is not already in the MST, add it to the priority queue
                if (!MST[vertex]) pq.push({vertexWeight, vertex});
            }
        }
        
        // Return the total weight of the Minimum Spanning Tree
        return totalWeight;
    }
};
