/*
485. Max Consecutive Ones
Link: https://leetcode.com/problems/max-consecutive-ones/

Problem Summary:
Given a binary array `nums`, return the maximum number of consecutive 1's in the array.

Example:
Input: nums = [1,1,0,1,1,1]
Output: 3

------------------------------------------------------
Brute Force Intuition:
- For each index, count consecutive 1's until a 0 is encountered.
- Track the maximum length of consecutive 1's.
- Time Complexity: O(n^2) (inefficient).
- Space Complexity: O(1).

Better Approach (Kadane-like idea):
- Traverse once, maintain a running count of consecutive 1's.
- Reset count to 0 when encountering 0.
- Track the maximum count across the traversal.
- Time: O(n)
- Space: O(1).

Optimal Approach (Sliding Window idea):
- Use two pointers `left` and `right`:
  - Expand `right` as long as nums[right] == 1.
  - Reset `left` after encountering 0.
- Track max window length of 1’s.
- Equivalent to linear scan solution but framed as windowing.
- Time: O(n)
- Space: O(1).

------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                maxCount = max(maxCount, count);
            }
            else{
                count = 0;
            }
        }
        return maxCount;
    }
};

