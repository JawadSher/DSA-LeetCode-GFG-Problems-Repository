#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph class definition
class Graph {
public:
    vector<vector<int>> adjacencyList;

    // Constructor to initialize the adjacency list
    Graph(int totalNodes) {
        adjacencyList.resize(totalNodes);
    }

    // Function to add an edge to the graph
    void addEdge(int sourceNode, int destinationNode, bool isDirected = false) {
        adjacencyList[sourceNode].push_back(destinationNode);
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);
        }
    }

    // Function to perform BFS traversal
    void bfs(int startNode) {
        vector<bool> visited(adjacencyList.size(), false); // Visited array
        queue<int> q; // Queue for BFS

        // Start BFS from the startNode
        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            // Process the current node (e.g., print it)
            cout << currentNode << " ";

            // Visit all unvisited neighbors
            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int totalNodes = 6;

    // Create the graph
    Graph g(totalNodes);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Perform BFS traversal starting from node 0
    g.bfs(0);

    return 0;
}
