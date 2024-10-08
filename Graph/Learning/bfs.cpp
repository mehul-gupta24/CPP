// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include <utility>
#include<list>
#include<limits>
#include<set>
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
    bool cycleDetectionByDFS_directed_fun(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfs_visited,int node){
        visited[node]=true;
        dfs_visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                bool ans=cycleDetectionByDFS_directed_fun(adj,visited,dfs_visited,neighbour);
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
                return cycleDetectionByDFS_directed_fun(adj,visited,dfs_visited,i);
            }
        }
        return false;
    }
    void topological_sort_dfs_fun(unordered_map<int,list<int>>adj,unordered_map<int,bool>&visited,stack<int>&st,int node){
        //only for directed acyclic graph(DAG)
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                topological_sort_dfs_fun(adj,visited,st,neighbour);
            }
        }
        st.push(node);
    }
    void topological_sort_dfs(vector<vector<int>>edges,int source,int vertices,int e){
        // topological sort - it is the linear order of vertices such that for every edge u-v , u always appear before v in that order
        //only on directed acyclic graph
        // acyclic - because if cycle present than infinite loop
        // directed as - we have to know by which edge which is connected , so that we can come to an ordering
        // If we arent able to find valid topological sort , then that directed graph contains cycle // very important
        // We need extra data structure that is stack for getting ordering , as we will be pushing neighbour and then after poping it we will store it in another array
        // for DAG
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        unordered_map<int,bool>visited;
        stack<int>st;
        for(int i=0;i<vertices;i++){
            if(!visited[i]){
                topological_sort_dfs_fun(adj,visited,st,i);
            }
        }
        //we got updated stack
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }

    }
    void topological_sort_bfs(vector<vector<int>>edges,int source ,int nodes,int e){
        //Kahn's Algorithm
        //for DAG
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>indegree(nodes+1);
        // 0 based vertices ,so no issue , otherwise indegree(nodes+1)
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<nodes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //bfs
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto neighbour:adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        for(auto i:ans){
            cout<<i<<" ";
        }
    }
    bool cycleDetectionByBFS_directed(vector<vector<int>>edges,int source,int nodes,int e){
        //invalid toppological sort - means cyclic graph
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        // adj list is made
        // now about indegree
        vector<int>indegree(nodes);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<nodes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            count++;
            for(auto neighbour:adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        // means normal acyclic graph is there,cycle not present
        if(count==0){
            cout<<"cycle is present";
            return true;
        }
        cout<<"cycle is not present";
        return false;
    }

    int shortest_path_in_UnDirectedGraph(vector<pair<int,int>>edges,int source,int dest,int nodes,int e){
        //undirected acyclic graph
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        queue<int>q;
        q.push(source);
        visited[source]=1;
        parent[source]=-1;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto neighbour:adj[front]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    parent[neighbour]=front;
                    q.push(neighbour);
                }
            }
        }
        //we have the parent vector now
        vector<int>ans;
        int count=0;
        ans.push_back(dest);
        while(dest!=source){
            dest=parent[dest];
            ans.push_back(dest);
            count++;
        }
        // we also have shortest path in count
        //we got dest , now need to reverse it
        reverse(ans.begin(),ans.end());
        return 0;
    }

    // unordered_map<int,pair<int,int>>> adj;
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u,int v,int weight){
        pair<int,int>p={v,weight};
        adj[u].push_back(p);
    }
    void printAdj(){
        for(auto it:adj){
            cout<<it.first<< " - ";
            for(auto i:it.second){
                cout<<"{ "<<i.first<<" , "<<i.second<<" } ";
            }
            cout<<endl;
        }
    }
    void topological_sort_dfs_fun_forShortestPathInDAG(unordered_map<int, list<pair<int, int>>>&adj,unordered_map<int,bool>&visited,stack<int>&st,int node){
        //only for directed acyclic graph(DAG)
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour.first]){
                topological_sort_dfs_fun_forShortestPathInDAG(adj,visited,st,neighbour.first);
            }
        }
        st.push(node);
    }
    void shortest_path_in_DirectedGraph(vector<vector<int>>edges,int n){
        // directed acyclic graph
        // as weights are there we will have adj list as unordered_map<int,list<pair<int,int>>>adj;
        // input 2d vector gives edges rows and 3 columns where 3rd column is weight value
        // unordered_map<int,list<pair<int,int>>>adj;
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0;i<edges.size();i++){
            // pair<int,int>p={edges[i][1],edges[i][2]};
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        // printAdj(adj);
        stack<int>st;
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                topological_sort_dfs_fun_forShortestPathInDAG(adj,visited,st,i);
            }
        }
        //now i have st stack with ordering of topological sort , now we need to pop that
        int source=1;//source node
        vector<int>distance(n);
        for(int i=0;i<n;i++){
            distance[i]=INT_MAX;
        }
        distance[source]=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(distance[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(distance[top]+i.second<distance[i.first]){
                        distance[i.first]=distance[top]+i.second;
                    }
                }
            }
        }
        //now we have distance array updated;
        for(int i=0;i<distance.size();i++){
            cout<<i<<" "<<distance[i]<<endl;
        }
    }

    void dijkstra(vector<vector<int>>edges,int nodes){
        unordered_map<int,list<pair<int,int>>>adj;
        //weights are there , and unweighted graph
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,edges[i][2]});
            adj[v].push_back({u,edges[i][2]});
        }
        //done with adj list
        //now distance array
        vector<int>dist(nodes,INT_MAX);
        int source=0;
        dist[source]=0;
        set<pair<int,int>>st;
        //set={distance,node},{},{}
        st.insert({dist[source],source});
        while(!st.empty()){
            auto get=st.begin();
            int length=get->first;
            int node=get->second;
            st.erase(st.begin());
            for(auto neighbour:adj[node]){
                int weight=neighbour.second;
                int v=neighbour.first;
                if(weight+length<dist[v]){
                    if(st.find({dist[v],v})!=st.end()){
                        st.erase({dist[v],v});
                    }
                    dist[v]=weight+length;
                    st.insert({dist[v],v});
                }
            }
        }
        //now we have updated dist array
        for(int i=0;i<dist.size();i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
    }
    // prims algorithm is used to find the minimum spanning tree 
    // spanning tree - when u convert graph into tree(means no cycle - means graph with no cycle) - n nodes , n-1 edges , every node is reachable to any other node

    // now what is MST(minimum spanning tree) - spanning tree in minimum cost of weights
    vector<pair<pair<int,int>,int>>calculatePrimsMST(int n,int m,vector<pair<pair<int,int>,int>>g){
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<g.size();i++){
            int u=g[i].first.first;
            int v=g[i].first.second;
            int w=g[i].second;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>key(n+1,INT_MAX);
        vector<bool>mst(n+1,false);
        vector<int>parent(n+1,-1);
        key[1]=0;
        parent[1]=-1;
        mst[-1]=false;
        for(int i=1;i<=n;i++){
            int u;
            int mini=INT_MAX;
            //find minimum wali node
            for(int v=1;v<=n;v++){
                if(mst[v]==false && key[v]<mini){
                    u=v;
                    mini=key[v];
                }
            }
            //mark min node as true;
            mst[u]=true;
            for(auto it:adj[u]){
                int v=it.first;
                int w=it.second;
                if(mst[v]==false && w<key[v]){
                    parent[v]=u;
                    key[v]=w;
                }
            }
        }
        vector<pair<pair<int,int>,int>>ans;
        for(int i=2;i<=n;i++){
            ans.push_back({{parent[i],i},key[i]});
        }
        return ans;
    }
    // Disjoint Set - 2 major elements - 1)findparent() or findset()
                                    //   2)Union() or Union_set()
                                    // Union by raank and path compression
    void UnionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        int x=findParent(parent,u);
        int y=findParent(parent,v);
        //parents have
        if(rank[x]<rank[y]){
            parent[x]=y;
        }
        else if(rank[v]<rank[x]){
            parent[y]=x;
        }
        else{
            // in same case we can make anyone parent to any node,either u or v,doesnt matter,just we have to update the rank
            parent[x]=y;
            rank[y]++;
        }
        // if 2 nodes are given , and we need to find that whether they belong to same component or not , then we can find their parent and compare if their parent are same then they belong to same component otherwise not.

    }
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
        // this is path compression where the parent of node is directly attached to the root node(parent of all)
    }
    void makeSet(vector<int>&parent,vector<int>&rank,int n){
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    bool cmp(vector<int>&a,vector<int>&b){
        // weights r in 2nd index column
        return a[2]<b[2];
    }
    int minimumSpanningTree_Krushkal(vector<vector<int>>&edges,int n){
        vector<int>parent(n);
        vector<int>rank(n);
        makeSet(parent,rank,n);
        // we dont need adjacency list ,we need a linear data structure - where we need to store (weight,u,v) - u and v are nodes , and by weight we are sorting it - means minimum weight number will be at the top
        int minWeight=0;
        sort(edges.begin(),edges.end(),cmp);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(findParent(parent,u)!=findParent(parent,v)){
                //means in different components , now we need to merge it
                minWeight+=w;
                UnionSet(u,v,parent,rank);
            }
        }
        //parent vector is updated
        return minWeight;
    }
    //Find bridge in a graph - 2 data structure - 2 array - 1)discovery time
                                                        //  2)lowest discovery time
    //Tarjan's Algorithm
    void dfs_getBridge(unordered_map<int,list<int>>&adj,int node,vector<bool>visited,vector<int>dis,vector<int>low_dis,int time,int parent){
        //tarjan algo
        visited[node]=true;
        dis[node]=time++;
        low_dis[node]=time++;
        for(auto neighbour:adj[node]){
            if(neighbour==parent){
                continue;
            }
            else if(!visited[neighbour]){
                dfs_getBridge(adj,neighbour,visited,dis,low_dis,time,node);
                low_dis[node]=min(low_dis[node],low_dis[neighbour]);
                if(dis[node]<low_dis[neighbour]){
                    //bridge is present
                    cout<<"bridge is present between node "<<node <<" and node "<<neighbour<<endl;
                    return;
                }
            }
            //else visited[neighbour] and neighbour!=parent
            else{
                //means backedge is there , so for sure no bridge ,so just need to update the lowest distance value;
                low_dis[node]=min(low_dis[node],dis[neighbour]); // why dis[neighbour] - that we will know in articulation point

            }
        }
    }
    void getBridge(vector<pair<int,int>>&edges,int nodes){
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dis(nodes); //discovery time array
        vector<int>low_dis(nodes); //lowest disc time array
        vector<bool>visited(nodes,false); //lowest disc time array
        int time=0;
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                dfs_getBridge(adj,i,visited,dis,low_dis,time,-1); // -1 is parent
            }
        }
    }
    
    void dfs_getArticulationPoint(vector<int>&ap,unordered_map<int,list<int>>&adj,int node,vector<bool>visited,vector<int>dis,vector<int>low_dis,int time,int parent){
        //tarjan algo
        visited[node]=true;
        dis[node]=time++;
        low_dis[node]=time++;
        int child=0;
        for(auto neighbour:adj[node]){
            if(neighbour==parent){
                continue;
            }
            else if(!visited[neighbour]){
                dfs_getArticulationPoint(ap,adj,neighbour,visited,dis,low_dis,time,node);
                low_dis[node]=min(low_dis[node],low_dis[neighbour]);
                if(dis[node]<=low_dis[neighbour] && parent!=-1){
                    //art point is present
                    ap.push_back(node);
                    return;
                }
                child++;
            }
            //else visited[neighbour] and neighbour!=parent
            else{
                //means backedge is there , so for sure no bridge ,so just need to update the lowest distance value;
                low_dis[node]=min(low_dis[node],dis[neighbour]); // why dis[neighbour] - that we will know in articulation point
            }
        }
        if(parent==-1 && child>1){
            ap.push_back(node);
        }
    }
    void getArticulationPoint(vector<pair<int,int>>&edges,int nodes){
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dis(nodes); //discovery time array
        vector<int>ap; // art point array
        vector<int>low_dis(nodes); //lowest disc time array
        vector<bool>visited(nodes,false); //lowest disc time array
        int time=0;
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                dfs_getArticulationPoint(ap,adj,i,visited,dis,low_dis,time,-1); // -1 is parent
            }
        }
        for(auto i:ap){
            cout<<i<<" ";
        }
        return;
    }

    //Kosaraju's Algorithm - SCC(strongly connected components (Directed Graph)
    // In a directed graph, a Strongly Connected Component is a subset of vertices where every vertex in the subset is reachable from every other vertex in the same subset by traversing the directed edges
    // It is not in undirected graph as there , there is no meaning of SCC , as full graph would be 1 SCC , as we can reach any node from any node in that SCC
    // Steps for Kosaraju's Algorithm - 1) Get nodes in stack (topological sort)
    //                                  2) Transpose the graph
    //                                  3) Do DFS according to stack nodes on the transpose graph
    void kosaraju_top_sort(unordered_map<int,list<int>>&adj,int node,vector<bool>&visited,stack<int>&st){
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                kosaraju_top_sort(adj,neighbour,visited,st);
            }
        }
        st.push(node);
    }
    void kosaraju_dfs(unordered_map<int,list<int>>&adj,int node,vector<bool>&visited){
        visited[node]=true;
        cout<<node<<" ";
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                kosaraju_dfs(adj,neighbour,visited);
            }
        }
    }
    void Kosaraju_algorithm(vector<vector<int>>&edges,int nodes){
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        //adj list created

        stack<int>st;
        vector<bool>visited(nodes,false);
        //top sort in stack
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                kosaraju_top_sort(adj,i,visited,st);
            }
        }
        // we got our stack

        // now transpose the graph
        unordered_map<int,list<int>>transpose_adj;
        for(auto neighbour:adj){
            int u=neighbour.first;
            visited[u]=false;
            for(auto num:neighbour.second){
                int v=num;
                transpose_adj[v].push_back(u);
            }
        }
        //transpose graph is ready
        while(!st.empty()){
            int front=st.top();
            st.pop();
            if(!visited[front]){
                kosaraju_dfs(adj,front,visited);
            }
            cout<<endl;
        }
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

    // g.topological_sort_dfs({{0, 1}, {1, 2}, {2, 0}}, 0, 3, 3);
    // g.topological_sort_dfs({{2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}}, 0, 6, 6);
    // cout<<endl;
    // g.topological_sort_bfs({{2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}}, 0, 6, 6);
    // g.topological_sort_dfs({{0,1}, {0,2} ,{1,3}, {2,3}, {3,4}}, 0, 5, 5);
    // cout<<endl;
    // g.topological_sort_bfs({{0,1}, {0,2} ,{1,3}, {2,3}, {3,4}}, 0, 5, 5);
    
    // cout<<g.cycleDetectionByBFS_directed({{0,1}, {1,2} ,{2,3}}, 0, 4, 3);

    // g.addEdge(1, 3, 6);
    // g.addEdge(1, 2, 2);
    // g.addEdge(0, 1, 5);
    // g.addEdge(0, 2, 3);
    // g.addEdge(3, 4, -1);
    // g.addEdge(2, 4, 4);
    // g.addEdge(2, 5, 2);
    // g.addEdge(2, 3, 7);
    // g.addEdge(4, 5, -2);
    // g.printAdj();
    // g.shortest_path_in_DirectedGraph({{1,3,6},{1,2,2},{0,1,5},{0,2,3},{3,4,-1},{2,4,4},{2,5,2},{2,3,7},{4,5,-2}},6);
    // this gives shortes path from source node to every node
    // g.dijkstra({{0,1,5},{0,2,8},{1,2,9},{1,3,2},{3,6,2}},4);
    //right

}
