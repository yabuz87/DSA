#include <iostream>
using namespace std;

struct Graph {
    int v;
    int e;
    int** adjMatrix;

    // Constructor to initialize the graph
    Graph(int vertices) {
        v = vertices;
        e = 0;
        adjMatrix = new int*[v];
        for(int i = 0; i < v; ++i) {
            adjMatrix[i] = new int[v];
            for(int j = 0; j < v; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Function to add an edge
    void addEdge(int a, int b) {
        if (a < v && b < v) {
            adjMatrix[a][b] = 1;
            adjMatrix[b][a] = 1;
            e++;
        } else {
            cout << "Invalid edge\n";
        }
    }

    // Destructor to clean up memory
    ~Graph() {
        for(int i = 0; i < v; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    Graph n(10);
    n.addEdge(0, 1); 

    // Display the adjacency matrix
    for (int i = 0; i < n.v; ++i) {
        for (int j = 0; j < n.v; ++j) {
            cout << n.adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
