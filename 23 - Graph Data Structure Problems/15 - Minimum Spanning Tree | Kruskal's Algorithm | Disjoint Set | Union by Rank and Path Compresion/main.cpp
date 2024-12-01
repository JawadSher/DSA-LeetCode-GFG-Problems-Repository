class Solution
{
    public:
    // Function to initialize the parent and rank arrays for Union-Find (Disjoint Set Union)
    void makeSet(vector<int>& rank, vector<int>& parent, int n){
        for(int i = 0; i < n; i++){
            parent[i] = i; // Each node is initially its own parent
            rank[i] = 0;   // Rank of each node is initialized to 0
        }
    }
    
    // Function to find the representative (root) of a set using path compression
    int findParent(vector<int>& parent, int node){
        if(parent[node] == node) 
            return node; // If the node is its own parent, it is the root
        // Recursively find the root and apply path compression
        return parent[node] = findParent(parent, parent[node]);
    }
    
    // Function to unify two sets using union by rank
    void unionSet(int source, int destination, vector<int>& parent, vector<int>& rank){
        // Find the roots of the sets for both nodes
        source = findParent(parent, source);
        destination = findParent(parent, destination);
        
        // Attach the smaller ranked tree under the larger ranked tree
        if(rank[source] < rank[destination]) 
            parent[source] = destination; // Attach source under destination
        else if(rank[destination] < rank[source]) 
            parent[destination] = source; // Attach destination under source
        else{
            // If ranks are equal, choose one root arbitrarily and increase its rank
            parent[destination] = source;
            rank[source]++;
        }
    }
    
    // Function to calculate the weight of the Minimum Spanning Tree (MST)
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        vector<vector<int>> edges; // Vector to store all edges in the graph
        
        // Convert adjacency list to an edge list
        for(int source = 0; source < V; source++){
            for(auto &neighbour : adj[source]){
                int destination = neighbour[0]; // Neighboring node
                int weight = neighbour[1];      // Weight of the edge
                
                // To avoid duplicate edges, only consider source < destination
                if(source < destination) 
                    edges.push_back({weight, source, destination});
            }
        }
        
        // Arrays to store the rank and parent of each node
        vector<int> rank(V);
        vector<int> parent(V);
        makeSet(rank, parent, V); // Initialize the rank and parent arrays
        
        // Sort the edges by weight (Kruskal's algorithm requires this step)
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0]; // Compare weights of the edges
        });
        
        int minWeight = 0; // Variable to store the total weight of the MST
        
        // Iterate through the sorted edges
        for(int i = 0; i < edges.size(); i++){
            int source = findParent(parent, edges[i][1]); // Find root of source
            int destination = findParent(parent, edges[i][2]); // Find root of destination
            int weight = edges[i][0]; // Weight of the current edge
            
            // If the nodes belong to different sets, include this edge in the MST
            if(source != destination) {
                minWeight += weight; // Add the weight of the edge to the MST
                unionSet(source, destination, parent, rank); // Union the sets
            }
        }
        
        return minWeight; // Return the total weight of the MST
    }
};
