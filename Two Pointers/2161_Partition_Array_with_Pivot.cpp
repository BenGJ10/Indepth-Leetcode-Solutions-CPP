/*
2161. Partition Array According to Given Pivot
Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/

------------------------------------------------------
Problem Summary:
Given an array `nums` and an integer `pivot`, rearrange the elements such that:  
1. All elements < pivot come first (in the same relative order).  
2. All elements == pivot come next (in the same relative order).  
3. All elements > pivot come last (in the same relative order).  

Return the rearranged array.

------------------------------------------------------
Brute Force Approach:
1. Create three arrays: `less`, `equal`, `greater`.  
2. Traverse `nums` and put elements into the appropriate array.  
3. Concatenate them into one result array.  

- Time Complexity: O(n)  
- Space Complexity: O(n)  

------------------------------------------------------
Optimal Approach (Counting Buckets + Placement):
1. Count how many numbers are `< pivot` and `== pivot`.  
   - This tells us where to place `< pivot`, `== pivot`, and `> pivot` numbers.  
2. Create a result array of size `n`.  
3. Traverse `nums` again:  
   - Place `< pivot` elements starting at index 0.  
   - Place `== pivot` elements starting after all `< pivot`.  
   - Place `> pivot` elements starting after that.  
4. Return result.  

- Time Complexity: O(n) (two passes)  
- Space Complexity: O(n) (result array)  

------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high;
        
        // Count elements < pivot and == pivot
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) low++;
            else if (nums[i] == pivot) same++;
        }

        vector<int> result(nums.size());
        high = same + low, same = low, low = 0;

        // Place elements into correct positions
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                result[low++] = nums[i];
            }
            else if (nums[i] == pivot) {
                result[same++] = nums[i];
            }
            else {
                result[high++] = nums[i];
            }
        }
        return result;
    }
};
