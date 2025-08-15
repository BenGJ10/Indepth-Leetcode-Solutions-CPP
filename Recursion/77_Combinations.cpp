/*
LeetCode: 77. Combinations
Link: https://leetcode.com/problems/combinations/

Problem:
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Generate all subsets of numbers from 1 to n and select only those with size k.
- This approach is inefficient due to generating many unnecessary subsets.

Optimal Approach: Backtracking with Pruning
- Start from number 1 and try including each number in the combination.
- Once the current combination size reaches k, store it in the result.
- Use pruning: stop exploring if the remaining numbers are insufficient to complete a combination.
  (Loop bound: start <= n - (k - current_size) + 1)
- This significantly reduces the number of recursive calls.

Time Complexity: O(C(n, k)) // Total number of combinations to generate.
Space Complexity: O(k)      // Recursion stack depth.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> result;
        backtrack(1, n, k, ans, result);
        return result;
    }

    void backtrack(int index, int n, int k, vector<int> &ans, vector<vector<int>> &result) {
        if (ans.size() == k) {
            result.push_back(ans);
            return;
        }
        // start should not go beyond the point where there are fewer numbers left than the number of spots we still need. 
        for (int start = index; start <= n - (k - ans.size()) + 1; start++) {
            ans.push_back(start);
            backtrack(start + 1, n, k, ans, result);
            ans.pop_back();
        }
    }
};
