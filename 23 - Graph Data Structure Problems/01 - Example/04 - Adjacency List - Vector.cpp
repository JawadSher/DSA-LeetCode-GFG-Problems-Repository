#include <iostream>
#include <vector>
using namespace std;

// Graph Class Definition
class Graph {
public:
    // Adjacency List represented using a vector of vectors
    vector<vector<int>> adjacencyList;

    // Constructor to initialize the adjacency list with the given number of nodes
    Graph(int totalNodes) {
        adjacencyList.resize(totalNodes); // Resize the vector to hold 'totalNodes' vectors
    }

    // Function to add an edge to the graph
    void addEdge(int sourceNode, int destinationNode, bool isDirected = false) {
        // Add the edge from source to destination
        adjacencyList[sourceNode].push_back(destinationNode);

        // If the graph is undirected, add the reverse edge
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);
        }
    }

    // Function to print the adjacency list
    void printGraph() {
        for (int node = 0; node < adjacencyList.size(); node++) {
            cout << node << " -> ";
            for (int neighbor : adjacencyList[node]) {
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

    // Create a Graph object
    Graph graphInstance(numberOfNodes);

    // Input edges
    cout << "Enter the edges (sourceNode destinationNode):" << endl;
    for (int i = 0; i < numberOfEdges; i++) {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;

        // Add the edge to the graph (default: undirected)
        graphInstance.addEdge(sourceNode, destinationNode, false);
    }

    // Print the graph representation
    cout << "Adjacency List of the graph:" << endl;
    graphInstance.printGraph();

    return 0;
}
