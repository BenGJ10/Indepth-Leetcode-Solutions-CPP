/*
LeetCode: 40. Combination Sum II
Link: https://leetcode.com/problems/combination-sum-ii/

Problem:
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
The solution set must not contain duplicate combinations.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Try all subsets of candidates and check if their sum equals the target.
- Use a set to store unique combinations to avoid duplicates.
- Very inefficient due to the large search space.

Optimal Approach: Backtracking with Sorting
- Sort the candidates to handle duplicates efficiently.
- Use a for loop in recursion starting from the current index.
- Skip duplicate numbers by checking if the current number is the same as the previous (and we’re still in the same recursion level).
- Prune the recursion if the current number exceeds the target.
- Each number is chosen at most once by moving to the next index after choosing it.

Time Complexity: O(2^n)  // Each candidate can be either chosen or not.
Space Complexity: O(n)   // Recursion stack depth.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        backtrack(0, target, candidates, ans);
        return result;
    }

    void backtrack(int index, int target, vector<int> &candidates, vector<int> &ans) {
        if (target == 0) {
            result.push_back(ans);
            return;
        }

        for (int start = index; start < candidates.size(); start++) {
            // Skip duplicates
            if (start > index && candidates[start] == candidates[start - 1]) continue;
            // Prune if current number exceeds target
            if (candidates[start] > target) break;

            ans.push_back(candidates[start]);
            backtrack(start + 1, target - candidates[start], candidates, ans);
            ans.pop_back();
        }
    }
};
