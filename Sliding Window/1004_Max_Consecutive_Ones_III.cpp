/*
LeetCode: 1004. Max Consecutive Ones III
Link: https://leetcode.com/problems/max-consecutive-ones-iii/

Approach:
- Maintain a sliding window [left, right] where the number of zeros does not exceed `k`.
- Expand the window by moving `right`.
- If the number of zeros in the window exceeds `k`, shrink the window from the left until it's valid.
- Update the maximum window length during the process.

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeroCount = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCount++;

            while (zeroCount > k) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};