#include <iostream>
#include <vector>
#include <stack> // Use stack instead of queue
using namespace std;

struct graph {
    int v;
    int e;
    vector<int> *adjList;
    bool *visited;
    graph(int vertice) {
        v = vertice;
        adjList = new vector<int>[v];
        visited = new bool[v];
        for (int i = 0; i < v; i++) {
            visited[i] = false;
        }
        e = 0;
    }
    ~graph() {
        delete[] adjList;
        delete[] visited;
    }
    void addEdge(int a, int b) {
        if (a < v && b < v) {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            e++;
        }
    }

    void DFS(int startingNode) {
        stack<int> s; // Stack for DFS
        s.push(startingNode);
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";
                for (int i : adjList[node]) {
                    if (!visited[i]) {
                        s.push(i);
                    }
                }
            }
        }
    }
};

int main() {
    graph g(6);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.DFS(0);
}
