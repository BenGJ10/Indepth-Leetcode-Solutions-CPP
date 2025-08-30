/*
1552. Magnetic Force Between Two Balls
Link: https://leetcode.com/problems/magnetic-force-between-two-balls/

Problem Summary:
We are given an array `position` of ball positions on a line and an integer `m` (number of balls).
We must place `m` balls in the baskets such that the **minimum magnetic force (distance) between any two balls is maximized**.

Brute Force Intuition:
- Try placing balls at different positions and check the minimum distance.
- Explore all combinations to find the maximum possible minimum distance.
- Time complexity: Exponential (not feasible for large n).

Optimal Approach Intuition (Binary Search on Answer):
- Observation: The maximum possible minimum distance lies between:
  - `1` (minimum distance),
  - and `max(position) - min(position)` (largest gap).
- Sort `position`.
- Use binary search on this distance:
  - For each mid (candidate distance), check if we can place at least `m` balls
    such that the gap between consecutive balls ≥ mid.
  - If possible → increase distance (left = mid+1).
  - Else → decrease distance (right = mid-1).
- Return the largest feasible distance.

Complexity:
- Time: O(n log(max_position)), since each binary search step requires scanning all positions.
- Space: O(1).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPutBalls(vector<int>& position, int m, int dist){
        int start = position[0], count = 1;
        for(int i = 1; i < position.size(); i++){
            if(position[i] - start >= dist){
                start = position[i];
                count++;
                if(count >= m) return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int ans = 1;
        int left = 1, right = position.back() - position.front();

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canPutBalls(position, m, mid)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};

