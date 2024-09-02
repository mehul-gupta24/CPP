// 78. Subsets
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void f(int index,vector<vector<int>> &ans,vector<int>&p,vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(p);
            // p.erase(p.begin(),p.end());
            return ;
        }
        f(index+1,ans,p,nums);
        p.push_back(nums[index]);
        f(index+1,ans,p,nums);
        p.pop_back();
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>p;
        f(0,ans,p,nums);
        return ans;
    }
};