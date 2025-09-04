/*
2226. Maximum Candies Allocated to K Children
Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

------------------------------------------------------
Problem Summary:
We are given:
- candies[i] → number of candies in the i-th pile.
- k → number of children.

Rules:
- Each child must receive the same number of candies.
- A pile can be split, but a child’s share must be whole candies.
- Goal: maximize the number of candies per child.

------------------------------------------------------
Brute Force Approach:
- Try all possible values from 1 up to max(candies).
- For each candidate value `x`, simulate:
  - Count how many children can be served if each child gets `x` candies.
- Return the maximum feasible `x`.
- Very slow if done linearly.

------------------------------------------------------
Optimal Approach (Binary Search on Answer):
1. Search space:
   - Left = 1 (minimum per child).
   - Right = max(candies) (largest pile).
2. For each mid (candidate candies per child):
   - Calculate total children served: sum(candies[i] / mid).
   - If total ≥ k → valid distribution, try higher (left = mid + 1).
   - Else → too many candies per child, reduce (right = mid - 1).
3. Track the maximum valid mid.

- Time Complexity: O(n log(max(candies)))  
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canDistributeToAll(vector<int> &candies, long long k, int perChild) {
        long long count = 0;
        for (auto candy : candies) {
            count += candy / perChild;   // how many children can be served from this pile
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistributeToAll(candies, k, mid)) {
                ans = mid;        // valid, try for bigger value
                left = mid + 1;
            } 
            else {
                right = mid - 1;  // invalid, decrease
            }
        }
        return ans;
    }
};

