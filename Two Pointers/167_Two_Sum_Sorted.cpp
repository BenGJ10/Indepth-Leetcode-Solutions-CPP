/*
LeetCode: 167. Two Sum II - Input Array Is Sorted  
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Problem:  
Given a **1-indexed sorted array** `numbers` and an integer `target`, return the indices of the two numbers 
such that they add up to `target`. Return the indices in ascending order.  
You must use only constant extra space.

Approach: Two-Pointer Technique  
- Initialize two pointers: `left` at start and `right` at end.
- Move pointers inward:
  - If sum == target: return the indices.
  - If sum > target: decrement `right` (reduce sum).
  - If sum < target: increment `left` (increase sum).

Time Complexity: O(n) — each pointer moves at most once across the array.  
Space Complexity: O(1) — no extra space used.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left <= right){
            if(numbers[left] + numbers[right] == target){
                return {left + 1, right + 1};
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else{
                left++;
            }
        }
        return {-1, -1};
    }
};