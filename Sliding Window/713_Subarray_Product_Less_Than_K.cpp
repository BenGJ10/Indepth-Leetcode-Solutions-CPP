/*
LeetCode: 713. Subarray Product Less Than K  
Link: https://leetcode.com/problems/subarray-product-less-than-k/

Problem:  
Given an array `nums` and an integer `k`, return the number of contiguous subarrays 
where the product of all elements is strictly less than `k`.

Approach: Sliding Window (Two Pointers)  
- Use two pointers (`left` and `right`) to maintain a sliding window.
- Expand the window by multiplying the current number.
- If the product becomes >= k, shrink the window from the left.
- For each valid window, add `(right - left + 1)` to the count since every subarray ending at `right` and starting between `left` and `right` is valid.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)  return 0;
        int left = 0, right = 0;
        int count = 0;
        long long product = 1;

        for(right = 0; right < nums.size(); right++){
            product *= nums[right];

            if(product >= k){
                product /= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count; 
    }
};