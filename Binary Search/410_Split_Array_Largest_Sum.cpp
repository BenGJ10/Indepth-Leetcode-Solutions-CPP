/*
410. Split Array Largest Sum
Link: https://leetcode.com/problems/split-array-largest-sum/

Problem Summary:
Given an array `nums` and an integer `k`, split the array into `k` non-empty contiguous subarrays
such that the largest sum among these subarrays is minimized. Return this minimized largest sum.

Brute Force Intuition:
- Try all possible ways of splitting into `k` parts.
- For each partitioning, compute the max subarray sum and minimize it.
- Time complexity: Exponential → not feasible.

Optimal Approach Intuition (Binary Search on Answer):
- Observation: The answer lies between:
  - `max(nums)` (since no subarray can have sum less than the largest element),
  - and `sum(nums)` (if we take all elements in one subarray).
- Use binary search on this range:
  - For each mid (possible largest subarray sum), check how many subarrays we would need
    if we limit each subarray sum ≤ mid.
  - If more than `k` subarrays are needed → increase lower bound.
  - Else → shrink upper bound.
- Finally, `left` gives the minimized largest sum.

Complexity:
- Time: O(n * log(sum of nums)), since each binary search step scans the array once.
- Space: O(1).
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findSubarrays(vector<int> &nums, int split){
        int subArrays = 1;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > split){
                subArrays++;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return subArrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(findSubarrays(nums, mid) > k){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};
