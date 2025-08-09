/*
LeetCode: 853. Car Fleet
Link: https://leetcode.com/problems/car-fleet/

Problem:
We are given `target` (destination), and for each car its starting `position` and `speed`.
Cars move towards the target, and if a faster car catches up to a slower car, they become a single fleet and travel together at the slower speed.
Return the number of car fleets that will arrive at the target.

-------------------------------------------------------
Brute Force Approach:
- Simulate movements second-by-second until all cars reach target.
- Check when cars merge into fleets.
- Time Complexity: O(n²) in worst case.
- Space Complexity: O(1)

-------------------------------------------------------
Optimal Approach:
1. Compute the time each car takes to reach the target: `(target - position[i]) / speed[i]`.
2. Pair each car’s position with its time to reach.
3. Sort cars by position in descending order (starting from closest to target).
4. Use a stack to track fleets:
   - If the current car takes more time than the top of the stack, it forms a new fleet.
   - Otherwise, it merges into the existing fleet (do not push).

Time Complexity: O(n log n) — sorting dominates.
Space Complexity: O(n) — for storing cars and stack.
*/

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        // Calculate time to reach target for each car
        for (int i = 0; i < n; i++) {
            double timeRequired = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], timeRequired});
        }

        // Sort cars by starting position in descending order
        sort(cars.rbegin(), cars.rend());

        stack<double> st;
        for (auto &car : cars) {
            double time = car.second;
            if (st.empty() || time > st.top()) {
                st.push(time); // New fleet
            }
            // Else, it merges into the fleet represented by st.top()
        }

        return st.size();
    }
};
