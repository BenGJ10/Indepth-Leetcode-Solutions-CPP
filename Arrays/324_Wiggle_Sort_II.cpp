/*
324. Wiggle Sort II
Link: https://leetcode.com/problems/wiggle-sort-ii/

------------------------------------------------------
Problem Summary:
Rearrange the numbers in nums so that:
    nums[0] < nums[1] > nums[2] < nums[3] ...
Basically, the sequence alternates between small and large.

Example:
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4] 
(One valid answer; multiple answers possible)

------------------------------------------------------
Brute Force Approach:
- Generate all permutations and check which one satisfies wiggle condition.
- Way too slow (O(n!)) → not feasible.

Better Approach (Sort + Fill):
1. Sort the array.
2. Split into two halves:
   - Left half = smaller elements
   - Right half = larger elements
3. Fill even indices with elements from left half (in reverse, largest smalls first).
4. Fill odd indices with elements from right half (in reverse, largest larges first).
- This ensures:
   - nums[0] < nums[1] because largest small < largest large.
   - nums[1] > nums[2] because largest large > next small.
- Time Complexity: O(n log n)
- Space Complexity: O(n) for the extra array.

Optimal Approach (O(n) with Median + 3-way Partition):
- Find median using nth_element.
- Use index mapping + 3-way partition (like Dutch National Flag).
- Rearrange elements around the median in one pass.
- Time Complexity: O(n)
- Space Complexity: O(1)
(This is more complex to code.)

------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int mid = (n + 1) / 2;
        int small = mid - 1, large = n - 1;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                nums[i] = sorted[small--];
            }
            else{
                nums[i] = sorted[large--];
            }
        }

        /*
        Why do we place from the back?
        - If we filled front-to-back, duplicates near the median might clump together
          (e.g., [2,2,2,3,3,3]) → violating wiggle.
        
          - By taking from the back, we distribute larger smalls and larger larges
          next to each other → preserving the wiggle property.
        */
    }
};
