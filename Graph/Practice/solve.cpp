#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph{
    public:
    //solving important concepts of graph
    vector<vector<int>>print_adjList(vector<vector<int>>&edges,int nodes,int no_of_edges){
        vector<vector<int>>ans;
        for(int i=0;i<nodes;i++){
            ans[i].push_back(i);
        }
        for(int i=0;i<edges.size();i++){
            // 2 nodes are taken
            int u=edges[i][0];
            int v=edges[i][1];
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        return ans;
    }
};