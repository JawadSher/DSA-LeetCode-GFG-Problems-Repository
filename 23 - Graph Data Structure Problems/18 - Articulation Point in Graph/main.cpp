class Solution {
  public:
    // Depth First Search to find articulation points
    void DFS(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, vector<int>& visited, vector<int>& AP, vector<vector<int>>& adjacencyList) {
        visited[node] = true;  // Mark the node as visited
        disc[node] = low[node] = timer++;  // Assign discovery time and initialize low
        int child = 0;  // Count of children in DFS tree

        // Traverse all neighbors of the current node
        for (auto neighbour : adjacencyList[node]) {
            if (neighbour == parent) continue;  // Skip the parent node

            if (!visited[neighbour]) {  // If the neighbor is not visited
                DFS(neighbour, node, timer, disc, low, visited, AP, adjacencyList);  // Recursively visit
                low[node] = min(low[node], low[neighbour]);  // Update low value for the current node

                // Check articulation point condition
                if (low[neighbour] >= disc[node] && parent != -1) {
                    if (find(AP.begin(), AP.end(), node) == AP.end()) AP.push_back(node);
                }
                child++;
            } else {
                low[node] = min(low[node], disc[neighbour]);  // Update low value if back edge exists
            }
        }

        // Check root node condition
        if (parent == -1 && child > 1) {
            if (find(AP.begin(), AP.end(), node) == AP.end()) AP.push_back(node);
        }
    }

    // Main function to find articulation points
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1);  // Discovery times
        vector<int> low(V, -1);   // Lowest discovery times
        vector<int> visited(V, false);  // Visited nodes
        vector<int> AP;  // Articulation points
        int timer = 0;  // Timer to assign discovery times
        vector<vector<int>> adjacencyList(V);

        // Convert adjacency list
        for (int i = 0; i < V; i++) {
            for (auto neighbour : adj[i]) adjacencyList[i].push_back(neighbour);
        }

        // Perform DFS for all connected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1, timer, disc, low, visited, AP, adjacencyList);
            }
        }

        // If no articulation points found, return {-1}
        if (AP.empty()) AP.push_back(-1);
        else sort(AP.begin(), AP.end());  // Sort the articulation points

        return AP;
    }
};
