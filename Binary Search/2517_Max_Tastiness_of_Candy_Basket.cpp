/*
2517. Maximum Tastiness of Candy Basket
Link: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/

------------------------------------------------------
Problem Summary:
You are given an array `price[]` of size n (prices of candies) and an integer `k`.  
You need to choose exactly `k` candies such that the "tastiness" of the basket is maximized.  

Tastiness of a basket is defined as:
    - The minimum absolute difference between the prices of any two chosen candies.

------------------------------------------------------
Brute Force Approach:
- Try all subsets of size `k` and calculate their tastiness.
- Keep track of the maximum tastiness found.
- Time Complexity: O(nCk * k^2) → not feasible for n up to 10^5.

------------------------------------------------------
Optimal Approach (Binary Search + Greedy):
1. **Sort the array** of prices.
2. Apply **binary search** on the possible answer range `[0, maxPrice - minPrice]`.
   - `mid` = candidate tastiness value.
   - Use a greedy check (`canStore`) to verify if we can pick `k` candies such that each chosen candy has at least `mid` difference from the previous one.
3. If `canStore` is true → tastiness `mid` is possible, try for higher (left = mid+1).
4. Otherwise → tastiness too large, try smaller (right = mid-1).
5. Final answer = maximum feasible tastiness.

- Time Complexity: O(n log n) [sorting + binary search with linear greedy check].
- Space Complexity: O(1).

------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canStore(vector<int> &price, int k, int diff) {
        int count = 1;
        int prev = price[0];
        for (int i = 1; i < price.size(); i++) {
            if (price[i] - prev >= diff) {
                count++;
                prev = price[i];
            }
            if (count >= k) return true;
        }
        return false;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int left = 0, right = price[n - 1] - price[0], ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canStore(price, k, mid)) {
                ans = mid;
                left = mid + 1; // try bigger tastiness
            } 
            else {
                right = mid - 1; // reduce tastiness
            }
        }
        return ans;
    }
};
