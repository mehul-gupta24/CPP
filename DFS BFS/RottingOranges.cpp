// 994. Rotting Oranges
// Solved
// Medium
// Topics
// Companies
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>visited=grid;
        int minute=0;
        int count=0;
        queue<pair<int,int>>Q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    Q.push({i,j});
                }
                else if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count==0){
            return 0;
        }
        if(Q.size()==0){
            return -1;
        }
        vector<pair<int,int>>dirn={{-1,0},{1,0},{0,1},{0,-1}};
        while(!Q.empty()){
            int size=Q.size();
            while(size){
                pair<int,int>index=Q.front();
                Q.pop();
                for(auto it:dirn){
                    int i=index.first+it.first;
                    int j=index.second+it.second;
                    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && visited[i][j]==1){
                        visited[i][j]=2;
                        Q.push({i,j});
                        count--;
                    }
                }
                size--;
            }
            minute++;
        }
        if(count==0) return minute-1;
        return -1;
    }
};