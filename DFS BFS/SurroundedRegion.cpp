// 130. Surrounded Regions
// Solved
// Medium
// Topics
// Companies
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

 

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Explanation:


// In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

// Example 2:

// Input: board = [["X"]]

// Output: [["X"]]

 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>&board,vector<vector<char>>& new_board,int row,int column){
        //base case
        if(row<0 || column<0 || row>=board.size() || column>=board[0].size() || board[row][column]=='X' || new_board[row][column]=='#'){
            return;
        }
        new_board[row][column]='#';
        dfs(board,new_board,row,column+1);
        dfs(board,new_board,row,column-1);
        dfs(board,new_board,row+1,column);
        dfs(board,new_board,row-1,column);
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>>new_board(board.size(),vector<char>(board[0].size(),'O'));
        // vector<vector<char>> new_board(board.size(), vector<char>(board[0].size(), 'O'));
        //1st check for boundaries 0's
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                dfs(board,new_board,i,0);
            }
            if(board[i][board[0].size()-1]=='O'){
                dfs(board,new_board,i,board[0].size()-1);
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){
                dfs(board,new_board,0,i);
            }
            if(board[board.size()-1][i]=='O'){
                dfs(board,new_board,board.size()-1,i);
            }
        }
        //new_board is updated
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(new_board[i][j]!='#' && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        // updated board
    }
};