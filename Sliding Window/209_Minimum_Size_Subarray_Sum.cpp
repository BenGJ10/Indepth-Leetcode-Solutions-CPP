/*
LeetCode: 209. Minimum Size Subarray Sum
Link: https://leetcode.com/problems/minimum-size-subarray-sum/

Approach:
- Use two pointers to maintain a sliding window [left, right].
- Expand the window by moving `right` and add to the running sum.
- When the sum becomes >= target, shrink the window from `left` to try and minimize the length.
- Update the minimum length accordingly.

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};