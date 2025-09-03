/*
1011. Capacity To Ship Packages Within D Days
Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

------------------------------------------------------
Problem Summary:
You are given an array `weights` representing the weights of packages, and an integer `days`.
- You must ship the packages in order (no reordering).
- Each day, you can ship packages with a total weight up to some capacity.
- Find the minimum ship capacity required to ship all packages within `days`.

------------------------------------------------------
Brute Force Approach:
- Try all capacities from max(weights) to sum(weights).
- For each capacity, check if it's possible to ship within `days`.
- Return the first valid capacity.
- Time Complexity: O(n * (sum - max)), which is too slow.
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Binary Search on Answer):
1. Define the search space:
   - Minimum capacity = max(weights) (a single package must fit).
   - Maximum capacity = sum(weights) (ship all packages in one day).
2. Use binary search between [left, right]:
   - For each mid (capacity guess), check how many days are needed.
   - If days needed ≤ given days → reduce capacity (search left).
   - Else → increase capacity (search right).
3. Return the smallest feasible capacity.

- Time Complexity: O(n * log(sum(weights) - max(weights)))  
  → Each check requires O(n), binary search runs in log(range).
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int canShipAll(vector<int> &weights, int days, int load) {
        int count = 1;
        int currLoad = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (currLoad + weights[i] > load) {
                count++;                  // start new day
                currLoad = weights[i];    // reset load
            } else {
                currLoad += weights[i];
            }
        }
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canShipAll(weights, days, mid) <= days) {
                right = mid - 1; // try smaller capacity
            } 
            else {
                left = mid + 1;  // need larger capacity
            }
        }
        return left;
    }
};

