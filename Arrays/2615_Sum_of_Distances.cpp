/*
LeetCode: 2615. Sum of Distances
Link: https://leetcode.com/problems/sum-of-distances/

Problem:
You are given a 0-indexed integer array nums.
For each index i, find the sum of |i - j| where nums[i] == nums[j] and j != i.
Return an array answer where answer[i] is the sum for index i.

-------------------------------------------------------
Naive Approach (Brute Force):
- For every index i, loop through all j and check if nums[i] == nums[j].
- Compute distance and add.
- Time Complexity: O(n^2) → Too slow for n up to 10^5.

-------------------------------------------------------
Optimized Approach (Two-Pass Scan using HashMaps):
Idea:
- We can split the calculation into two directions: 
    1. Contribution from the left side (indexes < i).
    2. Contribution from the right side (indexes > i).
- Maintain two hash maps:
    - freq[x] = count of occurrences of x so far.
    - sum[x] = sum of indices of x so far.

Pass 1 (Left to Right):
- For each index i:
    - If element x appeared before, 
      contribution = (i * freq[x]) - sum[x].
    - Update freq[x] and sum[x].

Pass 2 (Right to Left):
- Reset maps.
- For each index i (scanning backwards):
    - If element x appeared after, 
      contribution = sum[x] - (i * freq[x]).
    - Update freq[x] and sum[x].

This ensures each pair is only counted once in correct direction.

-------------------------------------------------------
Complexity:
Time: O(n) → Each element processed twice.
Space: O(n) → HashMaps store frequency and sum of indices.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, long long> freq, sum;

        // Pass 1: Left to Right
        for (int i = 0; i < n; i++) {
            int elem = nums[i];
            if (freq.count(elem)) {
                ans[i] += (long long)i * freq[elem] - sum[elem];
            }
            freq[elem]++;
            sum[elem] += i;
        }

        // Reset for right pass
        freq.clear(); sum.clear();

        // Pass 2: Right to Left
        for (int i = n - 1; i >= 0; i--) {
            int elem = nums[i];
            if (freq.count(elem)) {
                ans[i] += sum[elem] - (long long)i * freq[elem];
            }
            freq[elem]++;
            sum[elem] += i;
        }

        return ans;
    }
};
