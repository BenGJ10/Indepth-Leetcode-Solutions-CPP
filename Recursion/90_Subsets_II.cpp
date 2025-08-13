/*
LeetCode: 90. Subsets II
Link: https://leetcode.com/problems/subsets-ii/

Problem:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

-------------------------------------------------------
Approach / Insight:
- First, sort the array so that duplicates are next to each other.
- Use backtracking to explore all possible subsets.
- For each index:
    1. Include the current element and move to the next index.
    2. Skip all duplicates before exploring the exclusion branch.
- This ensures that subsets containing duplicates are only generated once.

-------------------------------------------------------
Optimal Approach: Backtracking with duplicate skipping
- Sorting ensures duplicates are adjacent.
- Skipping duplicates avoids generating repeated subsets.
- Recursion depth is bounded by `n`.

Time Complexity: O(2^n)   // Each element can be either included or excluded.
Space Complexity: O(n)    // Recursion stack + temporary subset storage.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<int> ans;
        vector<vector<int>> result;
        backtrack(nums, 0, ans, result);
        return result;
    }

private:
    void backtrack(vector<int> &nums, int index, vector<int> &ans, vector<vector<int>> &res) {
        if (index == nums.size()) {
            res.push_back(ans);
            return;
        }

        // Include current element
        ans.push_back(nums[index]);
        backtrack(nums, index + 1, ans, res);
        ans.pop_back();

        // Skip duplicates
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }

        // Exclude current element
        backtrack(nums, index + 1, ans, res);
    }
};
