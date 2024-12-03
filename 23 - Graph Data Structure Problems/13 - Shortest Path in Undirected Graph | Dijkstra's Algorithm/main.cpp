#include <iostream>
#include <climits>
#include <set>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

// Graph class to represent the graph structure
class graph {
public:
    // Adjacency list to store the graph. Each node maps to a list of pairs (neighbor, weight)
    unordered_map<int, list<pair<int, int>>> adjacencyList;

    // Function to add an edge between two nodes with a specified weight
    void addEdge(int source, int destination, int weight) {
        // Create pairs representing the edge and its weight
        pair<int, int> u = make_pair(destination, weight); // Edge from source to destination
        pair<int, int> v = make_pair(source, weight);      // Edge from destination to source (since the graph is undirected)

        // Add the edge to the adjacency list
        adjacencyList[source].push_back(u);
        adjacencyList[destination].push_back(v);
    }

    // Function to print the adjacency list representation of the graph
    void printAdjacencyList() {
        for (auto vertex : adjacencyList) { // Loop through each vertex in the adjacency list
            cout << vertex.first << " -> "; // Print the current vertex
            for (auto neighbour : vertex.second) // Loop through its neighbors
                cout << "(" << neighbour.first << ", " << neighbour.second << "), "; // Print neighbor and weight
            cout << endl;
        }
    }

    // Function to implement Dijkstra's Algorithm
    void DijkstraAlgorithm(int node, vector<int>& distance, set<pair<int, int>>& Set) {
        // Insert the source node with distance 0 into the set
        Set.insert({0, node});
        distance[node] = 0; // Initialize the source node's distance to 0

        // Process the set until it is empty
        while (!Set.empty()) {
            // Get the node with the smallest distance (top of the set)
            auto top = *(Set.begin());
            int nodeDistance = top.first; // Distance of the current node
            int currNode = top.second;    // Current node being processed

            // Remove the processed node from the set
            Set.erase(Set.begin());

            // Traverse all neighbors of the current node
            for (auto neighbour : adjacencyList[currNode]) {
                int neighborNode = neighbour.first;  // Neighbor node
                int edgeWeight = neighbour.second;   // Weight of the edge to the neighbor

                // Check if a shorter path to the neighbor exists
                if (nodeDistance + edgeWeight < distance[neighborNode]) {
                    // If the neighbor is already in the set, remove the old record
                    auto record = Set.find({distance[neighborNode], neighborNode});
                    if (record != Set.end())
                        Set.erase(record);

                    // Update the distance to the neighbor
                    distance[neighborNode] = nodeDistance + edgeWeight;

                    // Insert the updated record into the set
                    Set.insert({distance[neighborNode], neighborNode});
                }
            }
        }
    }
};

int main() {
    graph g; // Create a graph object

    // Add edges to the graph
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 9);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 6);

    // Print the adjacency list of the graph
    g.printAdjacencyList();

    int n = 4; // Number of nodes in the graph
    vector<int> distance(n, INT_MAX); // Initialize distances to all nodes as infinity (INT_MAX)
    set<pair<int, int>> Set; // Min-heap implemented using a set to store (distance, node) pairs

    int src = 0; // Define the source node for Dijkstra's algorithm
    g.DijkstraAlgorithm(src, distance, Set); // Call Dijkstra's algorithm

    // Print the shortest distances from the source node to all other nodes
    cout << "Shortest distances from node " << src << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (distance[i] == INT_MAX) // If the distance is still infinity, the node is unreachable
            cout << "INF" << endl;
        else
            cout << distance[i] << endl; // Print the distance to the node
    }

    return 0;
}
