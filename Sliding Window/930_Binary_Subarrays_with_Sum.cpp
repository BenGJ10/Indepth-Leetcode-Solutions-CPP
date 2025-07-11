/*
LeetCode: 930. Binary Subarrays With Sum  
Link: https://leetcode.com/problems/binary-subarrays-with-sum/

Problem:
Given a binary array nums and an integer goal, return the number of non-empty subarrays
with a sum equal to goal.

Approach:
- Define a helper function `atmost(nums, goal)` that counts subarrays with sum ≤ goal.
- Use a sliding window (`left` and `right`) to maintain a subarray with sum ≤ goal.
- Expand the window by moving `right`, and shrink it from the left if the sum exceeds `goal`.
- At each step, the number of valid subarrays ending at `right` is (right - left + 1).
- To count subarrays with exact sum = goal, use:
    atmost(goal) - atmost(goal - 1)
  This subtracts the number of subarrays with sum < goal from the number with sum ≤ goal.

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;
class Solution {
public:
    int atmost(vector<int> &nums, int goal){
        if(goal < 0) return 0;
        int left = 0, sum = 0, count = 0;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left++];
            }
            count += (right - left + 1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};
