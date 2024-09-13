// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
// #include <utility>
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
        //undirected
        queue<int>q;
        visited[node]=true;
        parent[node]=-1;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it:adj[front]){
                if(parent[front]!=it && visited[it]){
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
    bool cycle_dfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,int node,int parent){
        //undirected
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                bool a=cycle_dfs(adj,visited,neighbour,node);
                if(a){
                    return true;
                }
            }
            else if(neighbour!=parent){
                return true;
            }
        }
        return false;

    }
    bool cycleDetectionByDFS(vector<vector<int>>edges,int vertex,int edge,int source_node){
        //undirected
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>visited;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                bool ans=cycle_dfs(adj,visited,i,-1);
                if(ans) {
                    cout<<"cycle is present";
                    return true;
                }
            }
        }
        cout<<"cycle is not present";
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
    bool check_cycle_directed(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfs_visited,int node){
        visited[node]=true;
        dfs_visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                bool ans=check_cycle_directed(adj,visited,dfs_visited,neighbour);
                if(ans)
                    return true;
            }
            else if(dfs_visited[neighbour]){
                return true;
            }
        }
        dfs_visited[node]=false;
        return false;
    }
    bool cycleDetectionByDFS_directed(vector<pair<int,int>>edges,int source,int edge,int vertices){
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;
            adj[u].push_back(v);
        }
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfs_visited;
        for(int i=0;i<vertices;i++){
            if(!visited[i]){
                return check_cycle_directed(adj,visited,dfs_visited,i);
            }
        }
        return false;
    }

};
int main(){
    // int vertex=3;
    Graph g;
    // vector<int>ans=g.solve_for_bfs({{1,2},{2,3},{3,4},{4,1}},4,4,1);
    // vector<int>ans2=g.solve_for_bfs({{1,2},{2,3},{3,4},{4,1},{2,4}},4,5,1);
    // vector<int>ans=g.solve_for_dfs({{0, 2}, {0, 3}, {0, 1}, {2, 4}},5,4,0);
    // g.cycleDetectionByDFS({{0, 1}, {1, 2}, {2, 4}, {0, 2}},4,4,0);
    // g.cycleDetectionByDFS({{0, 1}, {1, 2}, {2, 4}, {0, 3}},5,4,0);
    
    // bool ans=g.cycleDetectionByDFS_directed({{0,1},{1,2},{2,3}},0,3,4);
    // if(ans){
    //     cout<<"cycle present";
    //     return 0;
    // }
    // cout<<"cycle is not present";

    

    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    cout<<endl;
}
