/*
LeetCode: 39. Combination Sum
Link: https://leetcode.com/problems/combination-sum/

Problem:
Given an array of distinct integers `candidates` and a target integer `target`, return all unique combinations of `candidates` 
where the chosen numbers sum to `target`. You may use each number an unlimited number of times.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Try all possible combinations of numbers and check if the sum equals the target.
- Highly inefficient due to repeated recomputation.

Optimal Approach: Backtracking
- At each step, choose to include the current element (and not advance the index) or skip it.
- If the target becomes 0, store the combination.
- If target < 0, prune the recursion.
- This ensures we explore only feasible combinations.

Time Complexity: O(2^(target/min_num))  // Each decision is include or exclude, bounded by target.
Space Complexity: O(target)              // Recursion stack depth.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        vector<int> ans;
        vector<vector<int>> result;
        backtrack(0, target, nums, ans, result);
        return result;
    }

    void backtrack(int index, int target, vector<int> &nums, vector<int> &ans, vector<vector<int>> &result) {
        if (target < 0) return;

        if (index == nums.size()) {
            if (target == 0) {
                result.push_back(ans);
            }
            return;
        }

        ans.push_back(nums[index]);
        // Include the current number and continue with the same index
        backtrack(index, target - nums[index], nums, ans, result);
        ans.pop_back();
        // Exclude the current number and move to the next index
        backtrack(index + 1, target, nums, ans, result);
    }
};
