#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct graph{
    int v;
    int e;
    vector<int> *adjList;
    bool *visited;
    graph(int vertice)
    {
        v=vertice;
        adjList=new vector<int>[v];
        visited=new bool[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
        }
        e=0;
         
    }
    ~graph()
    {
        delete[] adjList;
        delete[] visited;
    }
     void addEdge(int a,int b)
     {
        if(a<v && b<v)
        {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            e++;
        }
     }
    
    
     void DFS(int startingNode)
     {
        visited[startingNode]=true;
        cout<<startingNode<<" ";
        for(int i: adjList[startingNode])
        {
            if(!visited[i])
            {
                DFS(i);
            }
        }

     }
};
int main()
{
    graph g(6);
     g.addEdge(0,2);
     g.addEdge(1,3);
     g.addEdge(1,2);
     g.addEdge(3,2);t
     g.addEdge(3,4);
     g.addEdge(4,5);
     g.addEdge(4,6);
     g.addEdge(4,7);
     g.DFS(0);
}