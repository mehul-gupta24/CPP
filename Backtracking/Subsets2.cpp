// 90. Subsets II
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    void fun(int index,set<vector<int>>&ans,vector<int>store,vector<int>nums){   
        if(index>=nums.size()){
            ans.insert(store);
            return;
        }
        fun(index+1,ans,store,nums);
        store.push_back(nums[index]);
        fun(index+1,ans,store,nums);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> subsetsWithDup;
        vector<int>store;
        sort(nums.begin(),nums.end());
        fun(0,subsetsWithDup,store,nums);
        return vector<vector<int>>(subsetsWithDup.begin(),subsetsWithDup.end());
    }
};