#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// Graph Class Definition
class Graph {
public:
    unordered_map<int, list<int>> adjacencyList;  // To store adjacency list

    // Add an edge to the graph
    void addEdge(int sourceNode, int destinationNode, bool isDirected) {
        // Add the edge from source to destination
        adjacencyList[sourceNode].push_back(destinationNode);

        // If the graph is undirected, add the reverse edge
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);
        }
    }

    // Print the adjacency list of the graph
    void printGraph() {
        for (auto vertex : adjacencyList) {
            cout << vertex.first << " -> ";
            for (auto neighbor : vertex.second) {
                cout << neighbor << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numberOfNodes;
    cout << "Enter the number of nodes in the graph:" << endl;
    cin >> numberOfNodes;

    int numberOfEdges;
    cout << "Enter the number of edges in the graph:" << endl;
    cin >> numberOfEdges;

    Graph graphInstance;  // Create a Graph object

    // Input edges
    for (int i = 0; i < numberOfEdges; i++) {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;

        // Add the edge to the graph (default: undirected)
        graphInstance.addEdge(sourceNode, destinationNode, false);
    }

    // Print the graph representation
    graphInstance.printGraph();

    return 0;
}
