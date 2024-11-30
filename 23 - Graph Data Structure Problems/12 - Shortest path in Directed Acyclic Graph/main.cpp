#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <stack>
#include <unordered_map>

using namespace std;

// Class representing a graph
class Graph {
public:
    // Adjacency list to store the graph as source -> {destination, weight}
    unordered_map<int, list<pair<int, int>>> adjacencyList;

    // Method to add a directed edge with a weight
    void addEdge(int source, int destination, int weight) {
        pair<int, int> edge = make_pair(destination, weight); // Create a pair of destination and weight
        adjacencyList[source].push_back(edge);               // Add the edge to the adjacency list
    }

    // Method to print the adjacency list for visualization
    void printAdjacencyList() {
        for (auto vertex : adjacencyList) {
            cout << vertex.first << " -> ";
            for (auto neighbour : vertex.second) {
                cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
            }
            cout << endl;
        }
    }

    // Helper method for topological sorting (DFS-based)
    void topologicalSort(int node, vector<int>& visited, stack<int>& sortedNodes) {
        visited[node] = true; // Mark the current node as visited

        // Recursively visit all unvisited neighbors
        for (auto neighbour : adjacencyList[node]) {
            if (!visited[neighbour.first]) {
                topologicalSort(neighbour.first, visited, sortedNodes);
            }
        }

        // Push the current node onto the stack after processing all its neighbors
        sortedNodes.push(node);
    }

    // Method to calculate the shortest path from a given source in a DAG
    void getShortestPath(int source, vector<int>& distance, stack<int>& sortedNodes) {
        distance[source] = 0; // Distance to the source itself is 0

        // Process nodes in topological order
        while (!sortedNodes.empty()) {
            int currentNode = sortedNodes.top();
            sortedNodes.pop();

            // Update distances for all neighbors if the current node has a valid distance
            if (distance[currentNode] != INT_MAX) {
                for (auto neighbour : adjacencyList[currentNode]) {
                    if (distance[currentNode] + neighbour.second < distance[neighbour.first]) {
                        distance[neighbour.first] = distance[currentNode] + neighbour.second;
                    }
                }
            }
        }
    }
};

int main() {
    Graph graph;

    // Add edges with weights to the graph
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 2);
    graph.addEdge(3, 4, -1);
    graph.addEdge(4, 5, -2);

    // Print the adjacency list to visualize the graph
    graph.printAdjacencyList();

    int numNodes = 6;                       // Number of nodes in the graph
    stack<int> sortedNodes;                 // Stack to store nodes in topological order
    vector<int> visited(numNodes, 0);       // Visited array to keep track of visited nodes

    // Perform topological sort for all unvisited nodes
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            graph.topologicalSort(i, visited, sortedNodes);
        }
    }

    int source = 1;                         // Source node for shortest path calculation
    vector<int> distance(numNodes, INT_MAX); // Initialize distances to infinity

    // Compute the shortest paths from the source
    graph.getShortestPath(source, distance, sortedNodes);

    // Print the shortest path distances
    cout << "Shortest Path is : ";
    for (int i = 0; i < numNodes; i++) {
        if (distance[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << distance[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
