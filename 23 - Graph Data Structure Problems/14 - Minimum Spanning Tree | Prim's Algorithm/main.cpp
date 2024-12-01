#include<iostream>
#include<vector>
#include<list>
#include<climits>

using namespace std;

class Graph {
public:
    vector<list<pair<int, int>>> adjacencyList;  // Adjacency list to store the graph (each list element is a pair: destination vertex and edge weight)
    
    // Constructor to initialize the adjacency list with n vertices
    Graph(int n) {
        adjacencyList.resize(n); // Resize the adjacency list to have n vertices
    }

    // Method to add an undirected edge between source and destination with a given weight
    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back({destination, weight});
        adjacencyList[destination].push_back({source, weight});
    }

    // Method to print the adjacency list of the graph
    void printAdjacencyList() {
        for (int i = 0; i < adjacencyList.size(); ++i) {
            cout << i << " -> ";  // Print the vertex number
            for (auto neighbour : adjacencyList[i]) {  // Traverse through all neighbors of the vertex
                cout << "(" << neighbour.first << ", " << neighbour.second << "), ";  // Print destination vertex and weight
            }
            cout << endl;
        }
    }

    // Implementation of Prim's Algorithm to find the Minimum Spanning Tree (MST)
    void PrimsAlgorithm(int n, vector<int>& key, vector<bool>& MST, vector<int>& parent, int& totalWeight) {
        
        key[0] = 0; // Start from vertex 0, minimum key for starting point
        parent[0] = -1; // No parent for the start node
    
        for (int count = 0; count < n; ++count) {
            // Step 1: Find the node with the minimum key that is not yet in MST
            int minKeyValue = INT_MAX;  // Initialize minimum key value to infinity
            int selectedNode = -1;  // Variable to store the selected node with minimum key
            
            // Iterate through all nodes to find the node with the minimum key that is not in the MST
            for (int i = 0; i < n; ++i) {
                if (!MST[i] && key[i] < minKeyValue) {  // If the node is not in MST and has a smaller key
                    minKeyValue = key[i];  // Update the minimum key value
                    selectedNode = i;  // Update the selected node
                }
            }
    
            // Step 2: Include this node in MST
            MST[selectedNode] = true;  // Mark the node as included in MST
            
            // Step 3: Update the total weight of the MST by adding the key value of the selected node
            if (parent[selectedNode] != -1) {  // If the selected node has a parent
                totalWeight += key[selectedNode];  // Add its key value to the total weight
            }
    
            // Step 4: Visit all adjacent nodes and update their key values
            for (auto neighbor : adjacencyList[selectedNode]) {  // Traverse through all neighbors of the selected node
                int adjacentNode = neighbor.first;  // Get the adjacent node
                int edgeWeight = neighbor.second;  // Get the weight of the edge
                if (!MST[adjacentNode] && edgeWeight < key[adjacentNode]) {  // If the adjacent node is not in MST and the edge weight is smaller than its current key
                    key[adjacentNode] = edgeWeight;  // Update the key value of the adjacent node
                    parent[adjacentNode] = selectedNode;  // Set the parent of the adjacent node
                }
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph object with 5 vertices

    // Add edges to the graph (source, destination, weight)
    g.addEdge(0, 1, 2);  // Edge between vertex 0 and vertex 1 with weight 2
    g.addEdge(0, 3, 6);  // Edge between vertex 0 and vertex 3 with weight 6
    g.addEdge(1, 2, 3);  // Edge between vertex 1 and vertex 2 with weight 3
    g.addEdge(1, 4, 5);  // Edge between vertex 1 and vertex 4 with weight 5
    g.addEdge(1, 3, 8);  // Edge between vertex 1 and vertex 3 with weight 8
    g.addEdge(2, 4, 7);  // Edge between vertex 2 and vertex 4 with weight 7

    // Print the adjacency list of the graph
    cout << "Adjacency List of the Graph:" << endl;
    g.printAdjacencyList();

    int n = 5; // Number of vertices

    vector<int> key(n, INT_MAX);   // Key values for each node, initialized to infinity
    vector<bool> MST(n, false);    // To track nodes included in MST (initialize all as false)
    vector<int> parent(n, -1);     // To store the parent of each node in MST (initialize all as -1)
    int totalWeight = 0;           // To store the total weight of the MST

    // Apply Prim's algorithm to find the Minimum Spanning Tree
    g.PrimsAlgorithm(n, key, MST, parent, totalWeight);

    // Print the total weight of the Minimum Spanning Tree
    cout << "\nMinimum Spanning Tree Weight is: " << totalWeight << endl;

    // Optional: Print the MST edges (parent-child relationship with their respective edge weights)
    cout << "\nEdges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << " with weight " << key[i] << endl;
    }
    
    return 0;  // Return 0 to indicate successful execution
}
