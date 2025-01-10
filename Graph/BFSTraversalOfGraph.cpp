#include<iostream>
#include<vector>
using namespace std;
// Adjascency List representation in C++
// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}
 void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (int x : adj[d])
      cout << "-> " << x;
    cout<<"\n";
  }
}
int main() {
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    printGraph(adj, V);


    int visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    vector<int> queue;  // Create a queue for BFS
    visited[0] = 1;
    queue.push_back(0);
    while (!queue.empty()) {
        int s = queue.front();
        cout << s << " ";
        queue.erase(queue.begin());
        for (int i = 0; i < adj[s].size(); i++) {
            if (visited[adj[s][i]] == 0) {
                visited[adj[s][i]] = 1;
                queue.push_back(adj[s][i]);
            }
        }
        }
}