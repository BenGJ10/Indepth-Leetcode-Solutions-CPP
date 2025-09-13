/*
Biweekly Contest 165: Smallest Absent Positive Greater Than Average

Problem Summary:
You are given an integer array `nums`.  
Return the **smallest positive integer** that:
1. **Does not appear** in `nums`, and
2. Is **strictly greater than the average** of all elements in `nums`.

The average is defined as: (sum of elements) / (number of elements).

------------------------------------------------------
Optimal Approach (Hash Set + Search):
1. Compute the sum of all elements and store every **positive** integer
   from `nums` in an unordered_set for O(1) lookups.
2. Calculate the average as a double: `avg = sum / n`.
3. Start checking from `candidate = max(1, floor(avg) + 1)`,
   the smallest integer strictly greater than the average (but at least 1).
4. Increment `candidate` until it is **not** present in the set.
5. Return this candidate.

- Time Complexity:  O(n + k)  
  n for building the set, k is the gap until we find the missing integer
  (bounded since nums[i] ∈ [-100,100]).
- Space Complexity: O(n) for the hash set.

------------------------------------------------------
*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        unordered_set<int> positives;

        for (int x : nums) {
            sum += x;
            if (x > 0) positives.insert(x);
        }

        double average = static_cast<double>(sum) / n;
        int candidate = max(1, static_cast<int>(floor(average) + 1));

        while (positives.count(candidate)) {
            ++candidate;
        }
        return candidate;
    }
};