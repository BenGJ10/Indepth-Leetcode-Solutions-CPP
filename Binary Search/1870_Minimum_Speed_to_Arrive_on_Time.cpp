/*
1870. Minimum Speed to Arrive on Time
Link: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

------------------------------------------------------
Problem Summary:
You are given:
- dist[i]: the distance of the i-th train ride.
- hour: the total time available to complete the journey.

Rules:
- For every ride except the last one, you must arrive at an integer hour 
  (so the travel time must be rounded up using ceil).
- The last ride uses the exact fractional time.
- You must choose a constant train speed (integer) to travel.

Find the minimum integer speed to complete the journey within `hour`, 
or return -1 if it’s impossible.

------------------------------------------------------
Brute Force Approach:
- Try all possible speeds from 1 to 1e7.
- For each speed, simulate the journey and check if it fits within `hour`.
- Very slow → O(n * 1e7).

------------------------------------------------------
Optimal Approach (Binary Search on Speed):
1. Search space:
   - Left = 1 (min speed)
   - Right = 1e7 (constraint from problem statement).
2. For each mid (candidate speed):
   - Compute total time:
     - For rides except last → add ceil(dist[i] / speed).
     - For last ride → add exact dist[i] / speed.
   - If total time ≤ hour → valid speed, try smaller (move right).
   - Else → need more speed (move left).
3. Return the smallest feasible speed.

- Time Complexity: O(n log(1e7))  
  → Each check takes O(n), binary search over 1 to 1e7 ≈ log(1e7).
- Space Complexity: O(1).

------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canTravel(vector<int> &dist, double hour, int speed) {
        double time = 0.0;
        for (int i = 0; i < dist.size(); i++) {
            double t = (double)dist[i] / speed;
            if (i != dist.size() - 1) 
                time += ceil(t);  // intermediate rides → round up
            else 
                time += t;        // last ride → exact time
        }
        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e7, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canTravel(dist, hour, mid)) {
                ans = mid;        // valid speed, try smaller
                right = mid - 1;
            } 
            else {
                left = mid + 1;   // too slow, increase speed
            }
        }
        return ans;
    }
};


