/*
LeetCode: 216. Combination Sum III
Link: https://leetcode.com/problems/combination-sum-iii/

Problem:
Find all valid combinations of k numbers (1–9) that sum up to a given number target.
Each number can be used at most once, and combinations must be unique.

-------------------------------------------------------
Brute Force Approach:
- Generate all subsets of numbers from 1–9 and check if:
    1. The subset has size k.
    2. The sum equals target.
- This works but is inefficient due to generating all subsets.

-------------------------------------------------------
Optimal Approach: Backtracking with pruning
- Start from number 1, recursively choose or skip numbers.
- If current sum + candidate > target, break early (pruning).
- Stop recursion if subset size > k.
- Only push to result when size == k and sum == target.

Time Complexity: O(C(9, k))   // Choose k numbers from 1–9.
Space Complexity: O(k)        // Recursion stack + temporary combination storage.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> ans;
        vector<vector<int>> result;
        backtrack(1, k, target, 0, ans, result);
        return result;        
    }

private:
    void backtrack(int num, int k, int target, int sum, vector<int> &ans, vector<vector<int>> &result){          
        if(ans.size() == k){
            if(sum == target){
                result.push_back(ans);
            }
            return;
        }

        for(int i = num; i <= 9; i++){
            if(i + sum > target)  break; // pruning
            ans.push_back(i);
            backtrack(i + 1, k, target, sum + i, ans, result);
            ans.pop_back();
        }
    }
};
