// 46. Permutations
// Solved
// Medium
// Topics
// Companies
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void fun(vector<int>&num,vector<int>&store,vector<vector<int>>&ans,vector<bool>&visited){
        if(store.size()==num.size()){
            ans.push_back(store);
            return;
        }
        for(int i=0;i<num.size();i++){
            if(!visited[i]){
                store.push_back(num[i]);
                visited[i]=true;
                fun(num,store,ans,visited);
                store.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>store;
        vector<bool>visited(nums.size(),0);
        fun(nums,store,ans,visited);
        return ans;
    }
};