/*
LeetCode: 875. Koko Eating Bananas
Link: https://leetcode.com/problems/koko-eating-bananas/

Approach:
- Use Binary Search to find the minimum eating speed 'k'.
- Lower bound: 1 (slowest possible speed).
- Upper bound: max number of bananas in a pile (fastest needed).
- For each mid value, check if Koko can finish eating all bananas in `h` hours.
- Use helper function `canEatAll()` to calculate time taken for a given speed.

Time Complexity: O(n * log(max(pile)))
- n = number of piles
- log(max(pile)) for binary search range

Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int maxElement(vector<int> &piles) {
        int maxi = INT_MIN;
        for (int bananas : piles) {
            maxi = max(maxi, bananas);
        }
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;                      
        int right = maxElement(piles);     
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canEatAll(piles, h, mid)) {
                ans = mid;          // Mid is a valid speed, try to lower it
                right = mid - 1;
            } else {
                left = mid + 1;     
            }
        }
        return ans;
    }

    bool canEatAll(vector<int> &piles, int h, int k) {
        long long hours = 0;
        for (int bananas : piles) {
            hours += ceil((double)bananas / k);
        }
        return hours <= h;
    }
};
