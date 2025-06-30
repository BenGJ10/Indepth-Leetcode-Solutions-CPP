/*
LeetCode: 15. 3Sum
Link: https://leetcode.com/problems/3sum/

Problem:
Given an integer array nums, return all the unique triplets [nums[i], nums[j], nums[k]]
such that i != j != k and nums[i] + nums[j] + nums[k] == 0.

Approach:
- Sort the array.
- Fix one number (nums[i]) and use two pointers to find the rest.
- Skip duplicates for i, left, and right to avoid repeated triplets.

Time Complexity: O(n^2)
Space Complexity: O(1) extra (excluding output space)
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0){
                    left++;
                } else if(sum > 0){
                    right--;
                } else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};