/* Inclusion-Exclusion Principle

Let’s define:
    atmost(k) = number of subarrays with at most k distinct elements.
    atmost(k-1) = number of subarrays with at most k-1 distinct elements.

Then:
    atmost(k) - atmost(k-1) = number of subarrays with exactly k distinct elements.

Why this works? Any subarray with exactly K distinct elements:
        Is included in atmost(k)
        But is excluded in atmost(k-1)

Thus, the difference gives only those subarrays with exactly K distinct integers.
*/

/*
LeetCode: 992. Subarrays with K Different Integers
Link: https://leetcode.com/problems/subarrays-with-k-different-integers/

Problem:
Given an integer array `nums` and an integer `k`, return the number of subarrays
with exactly `k` distinct integers.

Approach:
- Use the idea that:
    subarraysWithKDistinct = atMost(k) - atMost(k - 1)
- The `atmost()` helper function calculates the number of subarrays with at most k distinct integers.
- Maintain a sliding window using two pointers `left` and `right`, and a frequency map.
- When the window exceeds k distinct elements, shrink it from the left.
- For each valid window, add (right - left + 1) to count.

Time Complexity: O(N)
Space Complexity: O(N)
*/
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int atmost(vector<int> &nums, int k){
        int count = 0, left = 0;
        unordered_map<int, int> mpp;

        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;
            
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left++;
            }

            count += (right - left + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};