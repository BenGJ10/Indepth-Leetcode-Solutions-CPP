/*
LeetCode: 80. Remove Duplicates from Sorted Array II  
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Approach:
- The array is sorted, so duplicates appear consecutively.
- We want each element to appear **at most twice**.
- Use a two-pointer approach:
  1. The `counter` pointer represents the position to place the next allowed number.
  2. Start from index 2 because the first two elements are always allowed.
  3. For each number at index `i`, check if it's **equal to the number at counter - 2**.
     - If it's **different**, it's valid to keep, and we assign it to `nums[counter]`.
     - Increment the counter.

Time Complexity: O(n) — one pass through the array.  
Space Complexity: O(1) — in-place modification.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();

        int counter = 2;
        for(int i = 2; i < nums.size(); i++) {
            // Only allow if current is not equal to the element two positions behind
            if(nums[i] != nums[counter - 2]) {
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};
