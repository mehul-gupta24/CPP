// 463. Island Perimeter
// Solved
// Easy
// Topics
// Companies
// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

// Example 1:


// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
// Example 2:

// Input: grid = [[1]]
// Output: 4
// Example 3:

// Input: grid = [[1,0]]
// Output: 4
 

// Constraints:

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 100
// grid[i][j] is 0 or 1.
// There is exactly one island in grid.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int ans=0;
    void calculate_perimeter(vector<vector<int>>& grid,int i,int j){
        int row=grid.size();
        int column=grid[0].size();
        if(i==0 || grid[i-1][j]==0){
            ans++;
        }
        if(i==row-1 || grid[i+1][j]==0){
            ans++;
        }
        if(j==0 || grid[i][j-1]==0){
            ans++;
        }
        if(j==column-1 || grid[i][j+1]==0){
            ans++;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    calculate_perimeter(grid,i,j);
                }
            }
        }
        return ans;
    }
};