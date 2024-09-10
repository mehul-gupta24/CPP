#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int >>adj;
    void add_edge(int u,int v,bool direction){
        // direction=0 means undirected edge
        // direction=1 means directed edge
        adj[u].push_back(v);
        if(direction){
            return;
        }
        adj[v].push_back(u);
    }
    void print_adjList(){
        for(auto it:adj){
            cout<<it.first<<" -> ";
            for(int neighbour:it.second){
                cout<<neighbour<<" , ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter the number of nodes ";
    cin>>n;
    int m;
    cout<<"Enter the number of edges";
    cin>>m;
    Graph g_1;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g_1.add_edge(u,v,0);

    }
    g_1.print_adjList();
}