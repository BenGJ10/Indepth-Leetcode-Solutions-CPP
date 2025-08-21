/*
LeetCode: 46. Permutations
Link: https://leetcode.com/problems/permutations/

Problem:
Given an array nums of distinct integers, return all possible permutations. 
You can return the answer in any order.

-------------------------------------------------------
Approach: Backtracking (Swap Method)
- We explore permutations by fixing one index at a time.
- At each recursion level, we swap the current index with each possible choice and recurse deeper.
- Once we reach index == nums.size(), we have formed one complete permutation → add it to result.
- After recursion, we backtrack (swap back) to restore the original array before trying the next possibility.

Example:
nums = [1,2,3]

Step 1: Fix index=0 → swap with i=0,1,2
Step 2: Recurse on index=1 for each swap
Step 3: Once index==3 (size reached), store permutation.

Time Complexity: O(n * n!) 
- n! permutations, each requires O(n) to copy into result.
Space Complexity: O(n) recursion stack (ignoring output storage).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }

private:
    void backtrack(int index, vector<int> &nums, vector<vector<int>> &res) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);                   // choose
            backtrack(index + 1, nums, res);              // explore
            swap(nums[i], nums[index]);                   // un-choose (backtrack)
        }
    }
};
