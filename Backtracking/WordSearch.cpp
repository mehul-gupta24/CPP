// 79. Word Search
// Solved
// Medium
// Topics
// Companies
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool fun(vector<vector<char>>&board,string &word,int index,int row,int column){
        if(index==word.length()-1){
            return true;
        }
        board[row][column]-=70;
        if(row>0 && board[row-1][column]==word[index+1] && fun(board,word,index+1,row-1,column)){
            return true;
        }
        if(column>0 && board[row][column-1]==word[index+1] && fun(board,word,index+1,row,column-1)){
            return true;
        }
        if(row<board.size()-1 && board[row+1][column]==word[index+1] && fun(board,word,index+1,row+1,column)){
            return true;
        }
        if(column<board[row].size()-1 && board[row][column+1]==word[index+1] && fun(board,word,index+1,row,column+1)){
            return true;
        }
        board[row][column]+=70;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0] && fun(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};