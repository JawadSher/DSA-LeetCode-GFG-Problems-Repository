class Solution {
public:
    // Helper function to perform DFS
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjacencyList) {
        visited[node] = true;
        for (auto neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adjacencyList);
            }
        }
    }

    // Function to check if (c, d) is a bridge
    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<vector<int>> adjacencyList(V);

        // Build adjacency list from adj[]
        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                adjacencyList[i].push_back(neighbor);
            }
        }

        // Temporarily remove edge (c, d)
        adjacencyList[c].erase(remove(adjacencyList[c].begin(), adjacencyList[c].end(), d), adjacencyList[c].end());
        adjacencyList[d].erase(remove(adjacencyList[d].begin(), adjacencyList[d].end(), c), adjacencyList[d].end());

        // Perform DFS from node `c`
        vector<int> visited(V, false);
        dfs(c, visited, adjacencyList);

        // Check if node `d` is reachable from `c`
        int isBridge = (visited[d] == false) ? 1 : 0;

        // Restore edge (c, d)
        adjacencyList[c].push_back(d);
        adjacencyList[d].push_back(c);

        return isBridge;
    }
};
