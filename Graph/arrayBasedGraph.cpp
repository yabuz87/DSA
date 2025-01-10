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

  // Destructor to clean up memory
    ~Graph() {
        for(int i = 0; i < v; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
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
    void display()
   { 
      // Display the adjacency matrix
    cout<<"this one is the adjacency matrix of the graph\n";
    cout<<"  _ _ _ _ _ _ \n";
    for (int i = 0; i <v; ++i) {
         cout<<"\n| ";
        for (int j = 0; j <v; ++j) {
            cout <<adjMatrix[i][j] << " ";
        }
        cout<<" |\n";
    }
   cout<<"  _ _ _ _ _ _ \n";
   }

  
   
};

int main() {
    Graph n(5);
    n.addEdge(0, 1);
    n.addEdge(0, 2);
    n.addEdge(4,2); 
    n.display();

    

    return 0;
}
