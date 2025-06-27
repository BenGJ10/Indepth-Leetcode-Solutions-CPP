/*
LeetCode: 56. Merge Intervals
Link: https://leetcode.com/problems/merge-intervals/

Problem:
Given a list of intervals, merge all overlapping intervals.

Approach:
1. Sort intervals by their start time.
2. Initialize an empty result list `merged`.
3. For each interval:
   - If `merged` is empty or no overlap, add interval.
   - Else, merge it with the last interval in `merged`.

Time Complexity: O(n log n) for sorting  
Space Complexity: O(n) for result vector
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for(auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // Overlapping case → merge intervals
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
