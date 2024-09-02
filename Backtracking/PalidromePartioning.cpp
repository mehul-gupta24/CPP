// 131. Palindrome Partitioning
// Solved
// Medium
// Topics
// Companies
// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkPalindrome(string temp,int start,int end){
        for(int i=start;i<=end;i++){
            if(temp[i]!=temp[end-i+start]){
                return false;
            }
        }
        return true;
    }
    void fun(vector<vector<string>>&ans,vector<string>&store,string &s,int index){
        if(index==s.length()){
            ans.push_back(store);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(checkPalindrome(s,index,i)){
                store.push_back(s.substr(index,i-index+1));
                fun(ans,store,s,i+1);
                store.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>store;
        int index=0;
        fun(ans,store,s,index);
        return ans;
    }
};