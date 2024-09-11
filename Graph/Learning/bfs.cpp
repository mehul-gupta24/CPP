// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<list>
using namespace std;
class Graph{
    public:
    void bfs(vector<int>&ans,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,int node){
        visited[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto neighbour:adj[front]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push(neighbour);
                }
            }
        }

    }
    vector<int> solve_for_bfs(vector<vector<int > >edges,int vertex,int edge,int source_node){
        //1st we need to make adjacency list
        unordered_map<int,list<int > >adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            // consider unweighted graph
            adj[v].push_back(u);
        }
        vector<int>ans;
        unordered_map<int,bool>visited;
        //here vertex is the total number of vertices,and we r traversing through it considering graph is starting from 0 and endnig at node value vertex-1
        // for disconnected component
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                bfs(ans,adj,visited,source_node);
            }
        }
        return ans;
    }
};

int main(){
    int vertex=3;
    Graph g;
    vector<int>ans=g.solve_for_bfs({{1,3},{2,3},{1,2}},3,3,1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
