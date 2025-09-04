/*
2187. Minimum Time to Complete Trips
Link: https://leetcode.com/problems/minimum-time-to-complete-trips/

------------------------------------------------------
Problem Summary:
- We have n buses, where time[i] is the time one bus takes to finish 1 trip.
- A bus can make multiple trips.
- Given `totalTrips`, return the minimum time needed so that the buses together
  complete at least `totalTrips` trips.

------------------------------------------------------
Brute Force Approach:
- Start from time = 1 and check how many trips all buses can finish.
- Increment time until trips ≥ totalTrips.
- Too slow (up to 1e14 steps).

------------------------------------------------------
Optimal Approach (Binary Search on Time):
1. Search space:
   - Left = 1
   - Right = min(time) * totalTrips
     (since the fastest bus doing all trips alone is the upper bound).
2. For each mid (candidate time):
   - Calculate total trips = Σ (mid / time[i]).
   - If totalTrips can be achieved → valid, try smaller time.
   - Otherwise → need more time, move right.
3. Keep track of the minimum valid time.

- Time Complexity: O(n log(min(time) * totalTrips))  
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canFinish(vector<int> &time, int totalTrips, long long givenTime) {
        long long trips = 0;
        for (auto t : time) {
            trips += givenTime / t;
            if (trips >= totalTrips) return true; // early stop
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canFinish(time, totalTrips, mid)) {
                ans = mid;       // valid, try smaller
                right = mid - 1;
            } 
            else {
                left = mid + 1;  // too small, need more time
            }
        }
        return ans;
    }
};

