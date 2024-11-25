#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjacencyList;  // Adjacency list representation of the graph

    // Constructor to initialize the graph with the given number of nodes
    Graph(int totalNodes) {
        adjacencyList.resize(totalNodes);  // Resize the adjacency list to fit the total nodes
    }

    // Method to add an edge to the graph
    void addEdge(int sourceNode, int destinationNode, bool isDirected = false) {
        adjacencyList[sourceNode].push_back(destinationNode);  // Add destination node to source node's adjacency list
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);  // For undirected graph, add the reverse edge
        }
    }

    // Recursive DFS implementation
    void dfsRecursive(int startNode, vector<bool>& visited) {
        visited[startNode] = true;  // Mark the node as visited
        cout << startNode << " ";  // Print the visited node

        // Visit all the unvisited neighbors of the current node
        for (int neighbor : adjacencyList[startNode]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);  // Recursively visit the neighbor
            }
        }
    }

    // Iterative DFS implementation using a stack
    void dfsIterative(int startNode) {
        vector<bool> visited(adjacencyList.size(), false);  // Keep track of visited nodes
        stack<int> s;  // Stack to manage the nodes

        s.push(startNode);  // Push the starting node into the stack

        while (!s.empty()) {
            int currentNode = s.top();  // Get the top node from the stack
            s.pop();  // Remove it from the stack

            if (!visited[currentNode]) {
                cout << currentNode << " ";  // Print the current node
                visited[currentNode] = true;  // Mark it as visited
            }

            // Push all unvisited neighbors of the current node into the stack
            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int totalNodes = 6;  // Total number of nodes in the graph

    Graph g(totalNodes);  // Create a graph object

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS Traversal (Recursive): ";
    vector<bool> visited(totalNodes, false);  // Visited array to track nodes
    g.dfsRecursive(0, visited);  // Perform DFS starting from node 0
    cout << endl;

    cout << "DFS Traversal (Iterative): ";
    g.dfsIterative(0);  // Perform iterative DFS starting from node 0
    cout << endl;

    return 0;
}
