// 1905. Count Sub Islands
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

// Return the number of islands in grid2 that are considered sub-islands.

 

// Example 1:


// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output: 3
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
// Example 2:


// Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
// Output: 2 
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
 

// Constraints:

// m == grid1.length == grid2.length
// n == grid1[i].length == grid2[i].length
// 1 <= m, n <= 500
// grid1[i][j] and grid2[i][j] are either 0 or 1.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&visited,int row,int column){
        if(row<0 || column<0 || row>=grid1.size() || column>=grid1[0].size()){
            return true;
        }
        if(grid2[row][column]==0 || visited[row][column]==1){
            return true;
        }
        if(grid1[row][column]==0){
            return false;
        }
        visited[row][column]=1;
        bool ans1=check(grid1,grid2,visited,row-1,column);
        bool ans2=check(grid1,grid2,visited,row+1,column);
        bool ans3=check(grid1,grid2,visited,row,column-1);
        bool ans4=check(grid1,grid2,visited,row,column+1);
        return ans1&&ans2&&ans3&&ans4;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        vector<vector<int>>visited(grid1.size(),vector<int>(grid1[0].size(),0));
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j]==1 && visited[i][j]!=1 && check(grid1,grid2,visited,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};