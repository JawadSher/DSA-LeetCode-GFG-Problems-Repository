#include <iostream>
#include <vector>

using namespace std;

// Template class to define a generic graph
template <typename T>
class Graph {
public:
    // 2D vector to store the adjacency matrix
    vector<vector<int>> adjacencyMatrix;

    // Constructor to initialize the adjacency matrix
    Graph(int totalVertices) {
        // Initialize a square matrix of size totalVertices x totalVertices with zeros
        adjacencyMatrix = vector<vector<int>>(totalVertices, vector<int>(totalVertices, 0));
    }

    // Function to add an edge to the graph
    void addEdge(T source, T destination, int weight = 1, bool isDirected = false) {
        // Add an edge from source to destination with the specified weight
        adjacencyMatrix[source][destination] = weight;

        // If the graph is undirected, also add the reverse edge
        if (!isDirected) 
            adjacencyMatrix[destination][source] = weight;
    }

    // Function to print the adjacency matrix
    void printMatrix(int totalVertices) {
        // Loop through each row of the matrix
        for (int row = 0; row < totalVertices; row++) {
            // Loop through each column of the matrix
            for (int col = 0; col < totalVertices; col++) {
                // Print the value at the current cell (row, col)
                cout << adjacencyMatrix[row][col] << " ";
            }
            // Print a newline at the end of each row
            cout << endl;
        }
    }
};

int main() {
    int totalVertices = 3; // Define the total number of vertices in the graph

    // Create a graph object with the specified number of vertices
    Graph<int> g(totalVertices);

    // Add directed edges to the graph
    g.addEdge(0, 1, 1, true); // Add edge from vertex 0 to vertex 1 with weight 1
    g.addEdge(1, 2, 1, true); // Add edge from vertex 1 to vertex 2 with weight 1
    g.addEdge(2, 0, 1, true); // Add edge from vertex 2 to vertex 0 with weight 1

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    g.printMatrix(totalVertices);

    return 0;
}
