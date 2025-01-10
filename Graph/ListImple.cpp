#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct graphList
{
    int v=0;
    int e=0;
    vector<int> *adj;

    graphList(int vertices)
    {
        v = vertices;
        adj = new vector<int>[v];
    }
    void addEdge(int a,int b)
    {
       if(a<v && b<v)
       {
           adj[a].push_back(b);
           adj[b].push_back(a);
           e+=1;
       }
       else
       {
           cout<<"Invalid edge\n";
       }
    }
    void display()
    {
        cout<<"adjacency list of the graph\n";
        for(int i=0;i<v;i++)
        {
            cout<<"\n "<<i<<" -> ";
            for(int i:adj[i])
            {
                cout<<i<<", ";
            }
        }
    }
    int get_edge()
    {
        return e;
    }
    void BFSTraversal(int root)
    {
        bool visited[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
        }
        queue<int> q;
        visited[root]=true;
        q.push(root);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(int i:adj[u])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }

    }

};
int main()
{
    graphList  p(8);
    p.addEdge(0,2);
    p.addEdge(1,3);
    p.addEdge(1,2);
    p.addEdge(3,2);
    p.addEdge(3,4);
    p.addEdge(4,5);
    p.addEdge(4,6);
    p.addEdge(4,7);    
    p.display();
    cout<<"\n";
    p.BFSTraversal(0);
    
    cout<<"\n"<<p.get_edge();
}