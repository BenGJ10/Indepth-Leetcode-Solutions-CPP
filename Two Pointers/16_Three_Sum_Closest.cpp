/*
LeetCode: 16. 3Sum Closest
Link: https://leetcode.com/problems/3sum-closest/

Problem:
Given an integer array nums of length n and an integer target, 
find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

Approach:
- Sort the array.
- Fix one element and apply the two-pointer technique to find the closest sum.
- Track the closest sum by comparing absolute differences with the target.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX / 2; // Prevent overflow in abs()
        
        for(int i = 0; i < nums.size() - 2; i++){
            int left = i + 1, right = nums.size() - 1;
            
            while(left < right){
                int curr = nums[i] + nums[left] + nums[right];
                if(abs(curr - target) < abs(closest - target)){
                    closest = curr;
                }
                if(curr < target){
                    left++;
                } else if(curr > target){
                    right--;
                } else{
                    return curr;
                }
            }
        }
        return closest;
    }
};