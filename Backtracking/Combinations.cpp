// 77. Combinations
// Solved
// Medium
// Topics
// Companies
// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void fun(vector<vector<int>>&ans,vector<int>&store,vector<int>&add,int index,int k){
        if(k==0){
            ans.push_back(add);
            return;
        }
        if(index>=store.size()){
            return;
        }
        add.push_back(store[index]);
        fun(ans,store,add,index+1,k-1);
        add.pop_back();
        fun(ans,store,add,index+1,k);
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>store;
        vector<int>add;
        for(int i=1;i<=n;i++){
            store.push_back(i);
        }
        vector<vector<int>>ans;
        int index=0;
        fun(ans,store,add,index,k);
        return ans;
    }
};