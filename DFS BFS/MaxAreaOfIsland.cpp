// 695. Max Area of Island
// Solved
// Medium
// Topics
// Companies
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&visited,int row,int column,int &maxi){
        if(row<0 || column<0 || row>grid.size()-1 || column>=grid[0].size() || grid[row][column]==0 || visited[row][column]==1){
            return;
        }
        maxi++;
        visited[row][column]=1;
        dfs(grid,visited,row-1,column,maxi);
        dfs(grid,visited,row+1,column,maxi);
        dfs(grid,visited,row,column-1,maxi);
        dfs(grid,visited,row,column+1,maxi);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && visited[i][j]!=1){
                    //means not visited
                    int store_earlier_maxi=maxi;
                    maxi=0;
                    dfs(grid,visited,i,j,maxi);
                    maxi=max(maxi,store_earlier_maxi);
                }
            }
        }
        return maxi;
    }
};