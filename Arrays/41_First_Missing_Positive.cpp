/*
LeetCode: 41. First Missing Positive  
Link: https://leetcode.com/problems/first-missing-positive/

Problem:
Given an unsorted integer array, find the smallest missing positive integer.  
You must solve it in O(n) time and use constant extra space.

Approach (Index Marking / Sign Flipping):
1. Replace all non-positive and out-of-bound numbers with n+1.
2. For each number in range [1, n], mark its index as visited by flipping the sign.
3. The first index with a positive value corresponds to the missing positive number.

Time Complexity: O(n)  
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Normalize the array
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = n + 1;
            }
        }

        // Step 2: Mark presence using negative signs
        for(int i = 0; i < n; i++){
            int num = abs(nums[i]);
            if(num <= n){
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Step 3: First index with positive value is the answer
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return n + 1;
    }
};