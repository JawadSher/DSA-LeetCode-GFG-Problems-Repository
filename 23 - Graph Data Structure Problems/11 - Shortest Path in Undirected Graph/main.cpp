class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> distance(N, -1);
        vector<bool> visited(N, false);
        queue<int> q;

        distance[src] = 0;
        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return distance;
    }
};
