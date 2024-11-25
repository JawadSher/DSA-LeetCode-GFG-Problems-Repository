#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
class graph{
    public:
        unordered_map<int, unordered_map<int, int>> adjacencyMatrix;
        
        void addEdge(T source, T destination, int weight = 1, bool isDirected = false){
            adjacencyMatrix[source][destination] = weight;
            if(!isDirected) adjacencyMatrix[destination][source] = weight;
        }
        
        void printMatrix(int totalVertices){
            for(int row = 0; row < totalVertices; row++){
                for(int col = 0; col < totalVertices; col++){
                    if (adjacencyMatrix[row].count(col) > 0) {
                        cout << adjacencyMatrix[row][col] << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }
        
};
int main() {
    graph<int> g;

    int totalVertices = 3;

    // Adding edges to the graph
    g.addEdge(0, 1, 1, true);
    g.addEdge(1, 2, 1, true);
    g.addEdge(2, 0, 1, true);

    // Printing the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    g.printMatrix(totalVertices);

    return 0;
}
