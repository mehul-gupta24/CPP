// 47. Permutations II
// Solved
// Medium
// Topics
// Companies
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    void fun(set<vector<int>>&ans,vector<int>&store,vector<int>&nums,vector<bool>&visited){
        if(store.size()==nums.size()){
            ans.insert(store);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                store.push_back(nums[i]);
                visited[i]=true;
                fun(ans,store,nums,visited);
                store.pop_back();
                visited[i]=false;
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int>store;
        vector<bool>visited(nums.size(),false);
        fun(ans,store,nums,visited);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};