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
    void dfs(vector<int>&ans,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,int node){
        ans.push_back(node);
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(ans,adj,visited,neighbour);
            }
        }
    }
    vector<int> solve_for_dfs(vector<vector<int>>edges,int vertex,int edge,int source_node){
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>visited;
        vector<int>ans;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                dfs(ans,adj,visited,i);
            }
        }
        return ans;
    }
    bool cycle_bfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,unordered_map<int,int>&parent,int node){
        queue<int>q;
        visited[node]=true;
        parent[node]=-1;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it:adj[front]){
                if(parent[it]!=front && visited[it]){
                    return true;
                }
                else if(!visited[it]){
                    q.push(it);
                    visited[it]=true;
                    parent[it]=front;
                }
            }
        }
        return false;
    }
    bool cycleDetectionByBFS(vector<vector<int>>edges,int vertex,int edge,int source_node){
        // for undirected graph
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                bool ans=cycle_bfs(adj,visited,parent,i);
                if(ans) {
                    cout<<"cycle is present";
                    return 1;
                }
            }
        }
        cout<<"cycle is not present";
        return false;
    }

};
int main(){
    // int vertex=3;
    Graph g;
    // vector<int>ans=g.solve_for_bfs({{1,2},{2,3},{3,4},{4,1}},4,4,1);
    // vector<int>ans2=g.solve_for_bfs({{1,2},{2,3},{3,4},{4,1},{2,4}},4,5,1);
    // vector<int>ans=g.solve_for_dfs({{0, 2}, {0, 3}, {0, 1}, {2, 4}},5,4,0);
    g.cycleDetectionByBFS({{0, 1}, {1, 2}, {2, 4}, {0, 3}},5,4,0);
    
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    cout<<endl;
}
