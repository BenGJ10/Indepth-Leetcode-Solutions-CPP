/*
LeetCode: 134. Gas Station
Link: https://leetcode.com/problems/gas-station/

Approach:
- We can only complete the circuit if total gas >= total cost.
- If at any point the gas becomes negative, it means we cannot start from that or any previous station.
- So we reset the start point to the next station.
- This ensures we get the earliest valid starting point that can complete the circuit.

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int start = 0, currGas = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currGas += gas[i] - cost[i];

            // If we can't reach the next station, reset start
            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }

        return totalGas < totalCost ? -1 : start;
    }
};