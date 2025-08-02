/*
Biweekly Contest 162: Earliest Finish Time for Land and Water Rides

Problem:  
You are given two categories of theme park rides: land and water.
- landStartTime[i] and landDuration[i]: start time and duration of each land ride.
- waterStartTime[j] and waterDuration[j]: start time and duration of each water ride.

A tourist must take exactly one land ride and one water ride (in any order).  
If a ride is started at time t, it finishes at t + duration.  
After finishing one ride, the tourist may take the other immediately if open, or wait until it opens.  

Return the earliest time at which the tourist can finish both rides.

Approach: Brute Force (O(n × m))
- Try all combinations of land → water and water → land.
- For each pair, compute finish time considering waiting.
- Return the minimum finish time.

Time Complexity: O(n × m)  (acceptable since n,m ≤ 100)  
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int ans = INT_MAX;

        // Case 1: Land → Water
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int finishLand = landStartTime[i] + landDuration[i];
                int startWater = max(finishLand, waterStartTime[j]);
                ans = min(ans, startWater + waterDuration[j]);
            }
        }

        // Case 2: Water → Land
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int finishWater = waterStartTime[j] + waterDuration[j];
                int startLand = max(finishWater, landStartTime[i]);
                ans = min(ans, startLand + landDuration[i]);
            }
        }

        return ans;
    }
};