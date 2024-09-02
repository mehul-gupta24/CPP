// 200. Number of Islands
// Solved
// Medium
// Topics
// Companies
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&visited,int row,int column){
        if(row<0 || row>=grid.size() || column<0 || column >=grid[0].size() || visited[row][column]==1 || grid[row][column]=='0'){
            return;
        }
        visited[row][column]=1;
        dfs(grid,visited,row+1,column);
        dfs(grid,visited,row-1,column);
        dfs(grid,visited,row,column-1);
        dfs(grid,visited,row,column+1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int column=grid[0].size();
        int count=0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;

    }
};