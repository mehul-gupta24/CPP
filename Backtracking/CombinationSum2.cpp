// 40. Combination Sum II
// Solved
// Medium
// Topics
// Companies
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    void fun(vector<vector<int>> &combinationSum2,vector<int>&store,vector<int>&candidates,int target,int index){
        if(target==0){
            combinationSum2.push_back(store);
            return;
        }
        if(index>=candidates.size() || target<0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(target-candidates[i]>=0){
                store.push_back(candidates[i]);
                fun(combinationSum2,store,candidates,target-candidates[i],i+1);
                store.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinationSum2;
        vector<int>store;
        sort(candidates.begin(),candidates.end());
        fun(combinationSum2,store,candidates,target,0);
        return combinationSum2;
    }
};